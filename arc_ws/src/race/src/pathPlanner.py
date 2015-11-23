#!/usr/bin/env python

import rospy

from race.msg import pid_input
from geometry_msgs.msg import PoseStamped

pub = rospy.Publisher('error', pid_input, queue_size=10)

x1 = 0.0
y1 = 0.0
x2 = 3.0
y2 = 3.0
vel = 14.4


def path_error(data):
	global x1
	global y1
	global x2
	global y2
	
	y = data.pose.position.y
	x = data.pose.position.x

	m = (y2-y1) / (x2-x1)
	error = y - m*x - c
	print "Error:", error

	msg = pid_input();
	msg.pid_error = error
	msg.pid_vel = vel
	pub.publish(msg)


def listener():
	rospy.init_node('pid_controller', anonymous=True)
	rospy.Subscriber("amcl_particle", PoseStamped, path_error)
	
	rospy.spin()


if __name__ == '__main__':
	print("Listening to error for PID")
	listener()