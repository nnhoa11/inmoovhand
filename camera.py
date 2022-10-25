import cv2
from cvzone.HandTrackingModule import HandDetector
import serial
from utlis import sendData, connectToRobot
cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon = 0.7, maxHands = 1)
serialcomm = serial.Serial('COM5', 9600)
serialcomm.timeout = 1
while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)
    if hands:
        hand1 = hands[0]
        fingers1 = detector.fingersUp(hand1)
        s = '$' + str(fingers1[0]) + str(fingers1[1]) + str(fingers1[2]) + str(fingers1[3]) + str(fingers1[4]);
        serialcomm.write(s.encode())
    cv2.imshow("image", img)
    key = cv2.waitKey(1)
    if key == ord('q'): break
cap.release()
cv2.destroyAllWindows
serialcomm.close()