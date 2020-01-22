import cv2
img = cv2.imread('circles.png')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
gray = cv2.GaussianBlur(gray, (9,9), 0)
circles = cv2.HoughCircles(gray, cv2.HOUGH_GRADIENT, 2, 20)
cv2.rectangle(img, (75, 147), (225, 297), (0,0,255), 2)
cv2.imwrite('boxedHough.png', img)
