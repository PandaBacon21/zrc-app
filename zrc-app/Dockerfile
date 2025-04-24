# PRODUCTION DOCKERFILE
# FROM nginx:alpine

# COPY dist/ /usr/share/nginx/html

# COPY nginx/default.conf /etc/nginx/conf.d/default.conf






# DEVELOPMENT DOCKERFILE
# Use Node image for development
FROM node:23-slim

# Set working directory
WORKDIR /app

# Install dependencies
COPY package*.json ./
RUN npm install

# Copy the rest of the app
COPY . .

# Expose the port Vite will run on
EXPOSE 5173

# Start the development server
CMD ["npm", "run", "dev"]
