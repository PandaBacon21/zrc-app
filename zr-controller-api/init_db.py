from app import create_app, db
from app.models.models import Token

app = create_app()

with app.app_context():
    # Create the database and tables
    db.create_all()
    print("Database created successfully.")