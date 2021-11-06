FROM node:12-alpine

RUN mkdir /app
COPY . /app
WORKDIR /app

RUN npm install && npm audit fix

EXPOSE 80
CMD node server.js