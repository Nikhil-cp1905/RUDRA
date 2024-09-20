import cv2
image=cv2.imread("imag.jpg")
window_name='Image'
image=cv2.rotate(image,cv2.ROTATE_90_CLOCKWISE)
image=cv2.rotate(image,cv2.ROTATE_90_CLOCKWISE)
cv2.imshow(window_name,image)
cv2.waitKey(0)
