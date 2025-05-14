import os 

from flask import Flask
from flask_cors import CORS
from flask_sqlalchemy import SQLAlchemy
from instance.config import Config

db = SQLAlchemy()

def create_app(config_class=Config):

    app = Flask(__name__, instance_relative_config=True)
    app.config.from_object(config_class)

    try: 
        os.makedirs(app.instance_path, exist_ok=True)
    except OSError: 
        print('Could not create instance directory or it already exists')

    db.init_app(app)
    CORS(app)

    with app.app_context():

        from .routes import api
        
        app.register_blueprint(api.api_bp, url_prefix='/api')
        
        return app




