docker stop iptables;docker rm iptables
docker run --name iptables --cap-add NET_ADMIN -it registry/iptables:v1 bash

