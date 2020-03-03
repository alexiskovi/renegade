function first_hit() {
  docker_images_list=$(docker images --format "{{.Repository}}")
  if [[ " ${docker_images_list[@]} " =~ "kovalexis/renegade_dev" ]]; then
    echo "[INFO] Found local renegade docker image..."
    return
  fi
  echo "[INFO] Installing renegade container..."
  #docker pull kovalexis/renegade_dev:latest
}

function stop_containers() {
  running_containers=$(docker ps --format "{{.Names}}")
  for i in ${running_containers[*]}
  do
    if [[ "$i" =~ renegade_* ]];then
      printf %-*s 70 "Stopping container: $i ..."
      docker stop $i > /dev/null
      if [ $? -eq 0 ];then
        printf "\033[32m[DONE]\033[0m\n"
      else
        printf "\033[31m[FAILED]\033[0m\n"
      fi
    fi
  done
}

IMG="kovalexis/renegade_dev"

while [ $# -gt 0 ]
do
  case "$1" in
  stop)
    stop_containers
    exit 0
    ;;
  *)
    echo -e "\033[93mWarning\033[0m: Unknown option: $1"
    exit 2
    ;;
  esac
  shift
done

function main() {
  current_containers=$(docker ps -a --format "{{.Names}}")
  if [[ " ${current_containers[@]} " =~ "renegade_dev" ]]; then
    echo "[INFO] Found stopped renegade docker container..."
    docker start -ai renegade_dev
    return
  else
    #set -x
    docker run -it \
          -d \
          --privileged \
          --name "renegade_dev" \
          --net host \
          -w /renegade \
          --add-host renegade_dev:127.0.0.1 \
          --hostname renegade_dev \
          --pid=host \
          -v $(pwd):/renegade \
	        -v /dev:/dev \
          $IMG \
          /bin/bash
    #set +x
  fi
  echo "Ready. Enjoy with docker/into_dev.sh!"
}

first_hit
main
