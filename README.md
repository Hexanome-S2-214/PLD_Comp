# PLD Comp

**Table of Contents**

- [Installation](#installation)
  - [Manually](#manually)
    - [antlr4](#antlr4)
      - [1. Using `apt-get`](#1-using-apt-get)
      - [2. Using the script](#2-using-the-script)
    - [Python dependencies (for testing)](#python-dependencies-for-testing)
  - [With Docker (recommended with Mac M1/M2 users)](#with-docker-recommended-with-mac-m1m2-users)
- [Usage](#usage)
  - [Build the project](#build-the-project)
  - [Testing the project](#testing-the-project)
    - [Using VSCode](#using-vscode)
    - [Using the command line](#using-the-command-line)
- [Continuous Integration](#continuous-integration)
- [Notes](#notes)
  - [Mac M1/M2 users](#mac-m1m2-users)

## Installation

### Manually

#### antlr4

There is two ways to install antlr4:

- Instally the dependencies using `apt-get` (recommended)
- Using the script `install_antlr4.sh`

##### 1. Using `apt-get`

```bash
sudo apt-get install antlr4 libantlr4-runtime-dev
```

##### 2. Using the script

```bash
./install_antlr4.sh
```

#### Python dependencies (for testing)

```bash
pip install -r requirements.txt
```

### With Docker (recommended with Mac M1/M2 users)

This project is configured to run with [devcontainers](https://code.visualstudio.com/docs/devcontainers/containers) in Visual Studio Code.

You need to have installed :

- [Docker](https://www.docker.com/)
- [Visual Studio Code](https://code.visualstudio.com/)
- [Devcontainers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)

Then, in the command palette, select `Dev Containers: Open Folder in Container...` and select the root of the project. The container will be built and you will be able to run the project.

## Usage

### Build the project

```bash
# Go to the root of the C++ project
cd compiler

# Run the build script
./runmake_ubuntu.sh # Or other runmake_*.sh depending on your OS
```

### Testing the project

The testing is done with Python (you need to have installed the Python dependencies).

#### Using VSCode

You can run the tests using the `Run Tests` button in the testing tab.

#### Using the command line

Make sure you are in the root of the project (not in the `compiler` directory).

```bash
python -m pytest
```

## Continuous Integration

The project is configured to run tests on GitHub Actions. The pipeline is configured in the file `.github/workflows/pipeline.yml`. This pipeline builds the project (the `ifcc` binary) and runs the tests. It will run automatically when you push on `origin/main` or when you create a pull request to `origin/main`.

A summary of the tests is available in the `Actions` tab of the repository.

## Notes

### Mac M1/M2 users

There are some difficulties working with antlr4 on Mac M1/M2. Working with Docker is recommended because it is able to run on a virtual machine with an x86 architecture.

In the `.devcontainer.json` file, there is a line which tells Docker to use the `x86_64` architecture:

```json
{
  "build": {
    "options": ["--platform=linux/amd64"]
    ...
  }
  ...
}
```

When this line is present, the C++ debugger will not work, but you will be able to test the project. If you want to debug the C++ code, you can remove this line and the C++ debugger will work, but you will not be able to test the project.

There is a limitation with the package `GDB` used to debug C++ code that does not support developping inside of Docker. Since our project writes assembly code for x86_64, we cannot test our project on a ARM architecture.

> Note: if you remove this line, you need to rebuild the container. You can do this by running the command `Dev Containers: Rebuild Container` in the command palette.