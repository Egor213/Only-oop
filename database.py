import os

from sqlalchemy import create_engine, Column, Integer, String
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy.orm import sessionmaker
from dotenv import load_dotenv

load_dotenv()

USER = os.getenv('USER', 'postgres')
PASSWORD = os.getenv('PASSWORD', 'admin')
SERVER = os.getenv('SERVER', 'localhost')
DATABASE = os.getenv('DATABASE', 'database')

SQLALCHEMY_DATABASE_URL = f"postgresql://{USER}:{PASSWORD}@{SERVER}/{DATABASE}"

engine = create_engine(SQLALCHEMY_DATABASE_URL)
SessionLocal = sessionmaker(autocommit=False, autoflush=False, bind=engine)

Base = declarative_base()

class Task(Base):
    __tablename__ = "tasks"
    id = Column(Integer, primary_key=True, index=True)
    name = Column(String, nullable=False)