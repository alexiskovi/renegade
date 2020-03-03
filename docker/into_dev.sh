xhost +local:root 1>/dev/null 2>&1
docker exec \
  -it renegade_dev \
  /bin/bash
xhost -local:root 1>/dev/null 2>&1
