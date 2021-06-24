# Zip 2D

## Docker
Build
```
docker build -t zip2d:latest .
```

Run
```
docker run -it --name zip2d --mount type=bind,source=<your current working directory>/src,target=/home zip2d:latest
```

Start
```
docker start zip2d
```

Exec
```
docker exec -it zip2d bash
```

Build
```
make
```

Execute
```
./main
```
