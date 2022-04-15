import cv2
from cvzone.HandTrackingModule import HandDetector
import serial 


cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon = 0.8, maxHands = 2)
while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)
    if hands:
        hand1 = hands[0]
        fingers1 = detector.fingersUp(hand1)
        print(fingers1)
        if len(hands) == 2:
            hand2 = hands[1]
            fingers2 = detector.fingersUp(hand2)
            print(fingers2)


    cv2.imshow("image", img)
    key = cv2.waitKey(1)
    