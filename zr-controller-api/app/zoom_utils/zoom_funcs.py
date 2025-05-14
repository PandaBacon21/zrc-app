import base64
import requests
import json

from flask import current_app
from .get_token import token

ZOOM_API_URL = current_app.config['ZOOM_API_URL']
ROOM_ID = current_app.config['ROOM_ID']

def create_headers():
    access_token = token()

    return {
        'content-type': 'application/json',
        'authorization': f'Bearer {access_token}'
    }

def zoomrooms_list():
    endpoint = '/rooms'
    full_url = ZOOM_API_URL+endpoint

    response = requests.get(url=full_url, headers=create_headers())
    print(f'endpoint: {endpoint}, status code: {response.status_code}')

    r_content = json.loads(response.content)
    rooms_list = r_content['rooms']
    return rooms_list

def zoomroom_toggle_camera(toggle, room_id=ROOM_ID):
    endpoint = f'/rooms/{room_id}/events'
    full_url = ZOOM_API_URL+endpoint

    if toggle: 
        command = 'zoomroom.video_unmute'
    else: 
        command = 'zoomroom.video_mute'

    body = {
        'method': command
    }

    response = requests.patch(url=full_url, headers=create_headers(), json=body)
    print(f'endpoint: {endpoint}, status code: {response.status_code}')

    if response.status_code == 202:
        return {'message': 'Camera toggled successfully!'}, 202
    else: 
        print(f'error: {response.status_code}')
        return {'message': 'An error occurred calling Zoom Cloud'}, response.status_code
    
def zoomrooms_accept_meeting(room_id='l0Bma8pPTlK7rq93NpKX4g'):
    endpoint = f'/rooms/{room_id}/events'
    full_url = ZOOM_API_URL+endpoint

    command = 'zoomroom.meeting_accept'

    body = {
        'method': command
    }

    response = requests.patch(url=full_url, headers=create_headers(), json=body)
    print(f'endpoint: {endpoint}, status code: {response.status_code}')

    if response.status_code == 202:
        return {'message': 'Zoom Room joined the meeting'}, 202
    else: 
        print(f'error: {response.status_code}')
        return {'message': 'An error occurred calling Zoom Cloud'}, response.status_code