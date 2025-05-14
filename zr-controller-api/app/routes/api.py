from flask import Blueprint, request, current_app

from ..zoom_utils.zoom_funcs import zoomroom_toggle_camera, zoomrooms_accept_meeting



api_bp = Blueprint('api', __name__)


@api_bp.route('/', methods=['GET'])
def index():
    return {'message': 'Welcome to the API!'}

@api_bp.route('/accept-meeting', methods=['GET'])
def accept_meeting():
    response = zoomrooms_accept_meeting()
    zoomroom_toggle_camera(False)
    return response



@api_bp.route('/toggle-camera', methods=['POST'])
def toggle_camera():
    toggle = request.json.get('cameraState')
    if toggle is None:
        return {'error': 'cameraState is required'}, 400
    if toggle not in [True, False]:
        return {'error': 'cameraState must be a boolean'}, 400
    response = zoomroom_toggle_camera(toggle)

    return response
