# Concurrent Multi-Client Server using Threads (C)

## 📌 Overview

This project implements a high-performance concurrent server in C that can handle multiple client connections simultaneously using POSIX threads (`pthreads`). Each client connection is served in a separate thread, allowing parallel request processing and improved responsiveness compared to single-threaded servers.

The server demonstrates core concepts of systems programming, including socket handling, multithreading, synchronization, and resource management.

---

## 🚀 Features

* Multi-client handling using threads
* TCP socket-based communication
* Scalable design for concurrent connections
* Thread lifecycle management (creation, execution, cleanup)
* Basic error handling and logging
* Graceful client disconnection support

---

## 🧠 Concepts Covered

* Socket Programming (TCP/IP)
* Multithreading with `pthread`
* Concurrent request handling
* Synchronization (mutexes, if implemented)
* File descriptors and I/O handling
* Client-server architecture

---

## 🏗️ Architecture

1. Server creates a listening socket.
2. Accepts incoming client connections.
3. For each client:

   * A new thread is spawned.
   * Thread handles communication with that client.
4. Main thread continues accepting new connections.

---

## 🔧 Tech Stack

* Language: C
* Libraries: POSIX (`pthread`, `sys/socket`, `netinet/in`)
* Platform: Linux / Unix-based systems

---

## ▶️ How to Run

### Compile

```bash
gcc server.c -o server -lpthread
```

### Execute

```bash
./server
```

### Connect via client (example using netcat)

```bash
nc localhost 8080
```

---

## 📂 Project Structure

```
.
├── server.c        # Main server implementation
├── client.c        # Optional test client
└── README.md       # Project documentation
```

---

## ⚠️ Limitations

* Thread-per-connection model may not scale well for very high loads
* No thread pool (can be added as an enhancement)
* Basic error handling (can be improved)

---

## 🔮 Future Improvements

* Implement thread pool for better scalability
* Add `select()` / `epoll()` based I/O multiplexing
* Introduce logging system
* Support for HTTP protocol
* Performance benchmarking

---

## 📚 Learning Outcomes

This project strengthens understanding of low-level system design and is especially useful for roles involving Linux systems, networking, and embedded environments.

---
