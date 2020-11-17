docker stop sig-proc;docker rm sig-proc
docker rmi registery/sig-proc:v1
docker build -t registery/sig-proc:v1 .
