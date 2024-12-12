from flask import Flask, request, jsonify
from flask_cors import CORS
from database import engine, SessionLocal, Base, Task
from sqlalchemy.exc import OperationalError

app = Flask(__name__)
CORS(app) 

def check_connection():
    try:
        with engine.connect() as connection:
            print("Connection successful!")
    except OperationalError as e:
        print(f"Error: {e}")

def create_tables():
    Base.metadata.create_all(bind=engine)
    print("Tables created!")

def create_task(task_name: str):
    db = SessionLocal()
    new_task = Task(name=task_name)
    db.add(new_task)
    db.commit()
    db.refresh(new_task)  
    db.close()

    return new_task  



@app.route('/', methods=['POST'])
def add_task():
    data = request.get_json()
    new_task = data.get('task')
    if new_task:
        return jsonify({
        "message": "Okey!"
        }), 200
    return jsonify({
        "error": "Task is empty!"
    }), 400




if __name__ == '__main__':
    check_connection()
    # app.run(debug=True)