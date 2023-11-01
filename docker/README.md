# Docker - Containerization

Running the project locally in a Docker container. `Links`: [Docker Documentation](https://docs.docker.com/get-started/), [CircleCI Documentation](https://circleci.com/docs/getting-started/).

- ## `Dockerfile:`

    ```bash
    FROM ubuntu:18.04
    WORKDIR /usr/src/app
    # Install g++, make, and cmake
    RUN apt-get update && apt-get install -y g++ make cmake
    # Copy your source code into the image
    COPY . .
    # Run cmake to generate a Makefile and then use make to build the project
    RUN cmake CMakeLists.txt && make
    EXPOSE 8080
    CMD [ "./main" ]
    ```

- ## `Docker Compose:`

    We use `docker-compose` to build and run multiple Docker container. This command uses a YAML file to configure the project's service in one go. Meaning, we create and start the service from our configuration file with a single command.

    - #### **Creating Images**:

        - We use the `docker-compose-build.yaml` file to create an image for the service. Then, we run the following command to create images locally:

            ```yaml
            version: "3"
            services:
            wackdonalds_restaurant_simulator:
                build:
                context: ./src
                image: wackdonalds_restaurant_simulator
            ```

        - ###### Removing unused and dangling images:
            ```bash
            docker image prune--all
            ```
        - ###### Creating images locally:
            ```bash
            docker-compose -f docker-compose-build.yaml build--parallel
            ```

    - #### **Running Containers**:

        - We run the containers using the images created in the step above. The `docker-compose.yaml` file will use the existing images and create containers. While creating containers, it defines the port mapping, and the container dependencies.

            ```yaml
            version: "3"
            services:
            wackdonalds_restaurant_simulator:
                image: wackdonalds_restaurant_simulator
                ports:
                    - 8080:8080
                restart: "no"  # always
            ```
        - **Starting the Project**:

            Once the `docker-compose-build.yaml` file is ready we start the application using:

            ```bash
            docker-compose up
            ```

    > **NB**: YAML files are extremely indentation sensitive.


---
---