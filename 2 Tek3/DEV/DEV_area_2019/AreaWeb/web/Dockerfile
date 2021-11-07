FROM node:latest

WORKDIR /usr/src/app

COPY package.json .

RUN npm install -g serve --silent
# Create app directory

# Install app dependencies
# A wildcard is used to ensure both package.json AND package-lock.json are copied
# where available (npm@5+)
# If you are building your code for production
# RUN npm install --only=production

EXPOSE 8081

CMD ["serve", "-s", "build", "-l", "8081"]