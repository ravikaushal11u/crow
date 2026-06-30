# Crow Framework Setup Guide (GitHub Codespaces)

## 📌 Project

Learning Crow C++ Web Framework (Django Style)

---

# 1. Clone Crow Repository

```bash
git clone https://github.com/CrowCpp/Crow.git
```

---

# 2. Project Structure

```
crow/
│
├── Crow/                  # Crow Framework Source
├── build/                 # Build Folder
├── templates/             # HTML Templates
│   └── home.html
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

# 3. Install Dependencies

Ubuntu / Codespaces

```bash
sudo apt update

sudo apt install -y \
g++ \
cmake \
libasio-dev
```

---

# 4. CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.16)

project(CrowHello)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Crow)

add_executable(CrowHello main.cpp)

target_link_libraries(CrowHello PRIVATE Crow::Crow)
```

---

# 5. Build Project

```bash
mkdir build

cd build

cmake ..

cmake --build .
```

---

# 6. Run Project

```bash
./CrowHello
```

Open

```
http://localhost:18080
```

---

# 7. Hello World Route

```cpp
#include <crow.h>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app,"/")
    ([]{
        return "Hello Ravi";
    });

    app.port(18080).multithreaded().run();
}
```

---

# 8. Using HTML Templates

Folder

```
templates/
    home.html
```

Example

```html
<!DOCTYPE html>
<html>
<head>
    <title>Crow</title>
</head>
<body>

<h1>Hello Ravi 🚀</h1>

</body>
</html>
```

---

# 9. Render HTML

```cpp
crow::mustache::set_global_base("../templates");

CROW_ROUTE(app,"/")
([]{

    auto page = crow::mustache::load("home.html");

    return page.render();

});
```

---

# 10. Common Errors

## Error

```
Template "home.html" not found
```

### Causes

- templates folder doesn't exist
- home.html missing
- wrong path
- wrong template base
- file not saved
- executable running from build folder

---

## Correct Path

If executable is inside

```
build/
```

and template is

```
templates/
```

then use

```cpp
crow::mustache::set_global_base("../templates");
```

---

cmake ..

cmake --build .
```

# Run
cd /workspaces/crow/build
```bash
./CrowHello
```

---

# 13. Folder Layout

```
crow/

│
├── Crow/
├── build/
├── templates/
│   └── home.html
├── main.cpp
├── CMakeLists.txt
└── README.md
```

---

# 14. Next Topics

- Routing
- HTML Templates
- CSS Static Files
- Bootstrap
- Forms
- GET
- POST
- SQLite
- Login
- Register
- Sessions
- Cookies
- REST API
- JWT
- File Upload
- MVC Architecture

---

# Goal

Learn Crow Framework exactly like Django and build production-ready C++ web applications.