from os import environ, path
from dotenv import load_dotenv

basedir = path.abspath(path.dirname(__file__))
load_dotenv(path.join(basedir, '.env'))

class Config():
    # Zoom Credentials
    ACCOUNT_ID = environ.get('ACCOUNT_ID')
    CLIENT_ID = environ.get('CLIENT_ID')
    CLIENT_SECRET = environ.get('CLIENT_SECRET')
    ZOOM_AUTH_URL = environ.get('AUTH_URL')
    ZOOM_API_URL = environ.get('API_URL')
    
    # Database
    SQLALCHEMY_DATABASE_URI = environ.get('DB_URI')
    SECRET_KEY = environ.get('SECRET_KEY')
    SQLALCHEMY_TRACK_MODIFICATIONS = False
    SQLALCHEMY_ECHO = False