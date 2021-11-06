FROM python:alpine

RUN mkdir /app
COPY . /app
WORKDIR /app

RUN pip install -r requirements.txt

EXPOSE 80
CMD flask run --host=0.0.0.0 --port=80