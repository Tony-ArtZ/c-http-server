# Simple C Web Server

This project is a basic web server written in C that serves static files (HTML, CSS, images, etc.) over HTTP. The server listens on port 8080 and handles GET requests to serve files from the project directory.

## Features
- Serves static HTML, CSS, JavaScript, and image files.
- Basic MIME type detection based on file extensions.
- Handles `GET` requests and returns 404 for missing files.
- Built using low-level socket programming and system calls.

## Directory Structure

```
├── MakeFile         # Compilation instructions
├── a.out            # Executable (optional, can be ignored)
├── about.html       # Sample HTML file
├── handler.c        # Handles incoming client requests
├── index.html       # Main page served by the server
├── main.c           # Entry point of the server program
├── mime.c           # MIME type detection based on file extension
├── public/          # Static assets (CSS, images)
│   ├── index.css    # Stylesheet
│   └── space.jpg    # Example image
├── server.c         # Socket setup and HTTP response handling
├── server.h         # Header file for shared function prototypes
```

## Compilation and Execution

### Prerequisites

- You need to have `gcc` and `make` installed on your system. If you are using Ubuntu in WSL, you can install them with:
  
  ```bash
  sudo apt update
  sudo apt install build-essential
  ```

### Build the Project

You can compile the project using the provided `MakeFile`:

```bash
make
```

This will generate an executable named `server`.

### Running the Server

After compiling, you can run the server with:

```bash
./server
```

The server will start listening on `localhost:8080`.

### Accessing the Server

Once the server is running, open your web browser and navigate to:

```
http://localhost:8080
```

You can view the `index.html` or other files in the directory. For example, you can also access:

```
http://localhost:8080/about.html
http://localhost:8080/public/index.css
http://localhost:8080/public/space.jpg
```

## Clean Up

To remove the compiled files (object files and executables), run:

```bash
make clean
```
