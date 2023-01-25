//PYCHARM
// This file is to identify human real-time motion 
// and ensure safety precautions are in place
  
  //Open cv library import
  import cv2
  from cvzone.HumanDetectionModule import HumanDetector
  from cvzone.SerialModule import SerialObject
  
  cap = cv2.VideoCapture(1)
  detector = HumanDetector()
  arduino = SerialObject()
  
  //While statement (bboxs is bounding boxes)
  
  while True:
    success, img = cap.read()
    img, bboxs = detector.findHumans(img)
    
    //Integration can be linked to serial, led.
    if bboxs:
      arduino.sendData([1]) //turns led on
    // link led to safety function for default state
  
    cv2.imshow("Human Detected", img)
    cv2.waitKey(1)
    
  // Integrate functionality with arduino or ros, where successful detection will
  // retract gripper to default state and output message
  ...
  
