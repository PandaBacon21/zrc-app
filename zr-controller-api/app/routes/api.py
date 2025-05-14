from flask import Blueprint, request, current_app



api_bp = Blueprint('api', __name__)


@api_bp.route('/', methods=['GET'])
def index():
    return {'message': 'Welcome to the API!'}


@api_bp.route('/toggle-camera', methods=['POST', 'GET'])
def toggle_camera():
    data = request.json.get('cameraState')


# testing that connection is made - will update logic 
    if data is None:
        return {'error': 'cameraState is required'}, 400
    if data not in [True, False]:
        return {'error': 'cameraState must be a boolean'}, 400
    if data == True:
        # Logic to turn on the camera
        print("Camera turned on")
    else:
        # Logic to turn off the camera
        print("Camera turned off")
    return {'message': 'Camera toggled successfully!'}
