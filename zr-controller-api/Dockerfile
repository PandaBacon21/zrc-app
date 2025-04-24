FROM ubuntu:latest

# Install dev tools
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    g++ \
    clang \
    libssl-dev \
    libboost-all-dev \
    libcurl4-openssl-dev \
    libasio-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

# Install Crow 
RUN git clone https://github.com/CrowCpp/crow.git /crow


CMD ["bash"]