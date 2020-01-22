import cv2

img = cv2.imread('circles.png')
template = cv2.imread('template.png')

mt = cv2.matchTemplate(img, template, cv2.TM_CCOEFF)

_, _, _, max_loc = cv2.minMaxLoc(mt)

bottom_right = (225, 297)

cv2.rectangle(img, max_loc, bottom_right, (0,0,255), 2)
cv2.imwrite('boxed.png', img)