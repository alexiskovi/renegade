import pygame
import rospy
from control.msg import control_cmd

MAX_THROTTLE = 125
MAX_STEERING = 100
MIN_STEERING = 50
STEERING_STEP = 5



def main():

  pygame.init()
  clock = pygame.time.Clock()
  joysticks = []

  for i in range(0, pygame.joystick.get_count()):
    joysticks.append(pygame.joystick.Joystick(i))
    joysticks[-1].init()
  
  if joysticks == []:
    print("No joysticks found!")
    return

  cmd_pub = rospy.Publisher('/renegade/control', control_cmd, queue_size=10)
  rospy.init_node('teleop_gamepad')
  rate = rospy.Rate(100)

  throttle_cmd = 0
  direction_cmd = 0
  steering_cmd = 75

  while 1:
    cmd = control_cmd()
    clock.tick(70)
    for event in pygame.event.get():

      if event.type == pygame.JOYAXISMOTION:
        if event.axis == 1:
          throttle_cmd = int(-event.value * MAX_THROTTLE)
          if throttle_cmd < 0:
            throttle_cmd *= -1
            direction_cmd = 1
          else:
            direction_cmd = 0
        if event.axis == 3:
          steering_cmd = 75 - int(-event.value * (MAX_STEERING - 75))
          if steering_cmd > MAX_STEERING:
            steering_cmd = MAX_STEERING
          if steering_cmd < MIN_STEERING:
            steering_cmd = MIN_STEERING

      if event.type == pygame.JOYBUTTONDOWN:
        if event.button == 7: # START
          print("Exit")
          return
    
    cmd.direction = direction_cmd
    cmd.throttle = throttle_cmd
    cmd.steering = steering_cmd

    cmd_pub.publish(cmd)
    rate.sleep()
    
if __name__ == "__main__":
  main()