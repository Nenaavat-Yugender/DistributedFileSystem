# Distributed File System

This project implements a simple Distributed File System that allows clients to upload and download files from a central server. The server stores files and handles requests from multiple clients. The client interacts with the server to perform operations like uploading, downloading, and listing files.

## Architecture

### 1. **Server (server.cpp)**
   - Handles file storage and manages client requests.
   - Listens for incoming client connections and processes file operations.
   
### 2. **Client (client.cpp)**
   - Sends requests to the server to upload or download files.
   - Allows the user to specify operations (upload, download, etc.) via a command-line interface.
   
### 3. **Utils (utils.cpp & utils.h)**
   - Helper functions for file operations, request parsing, and error handling.
   
### 4. **CMakeLists.txt**
   - Used to compile the project using CMake.
   
### 5. **README.md**
   - Documentation for the project, including setup instructions and usage.

## Features

- **File Upload**: Clients can upload files to the server.
- **File Download**: Clients can download files from the server.
- **File Listing**: Clients can list all files stored on the server.
- **Error Handling**: Proper error messages for missing files, invalid requests, and failed operations.

## Setup Instructions

1. **Clone the repository**:
   ```bash
   git clone <repository_url>
   cd DistributedFileSystem
