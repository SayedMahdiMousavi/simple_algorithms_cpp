import cv2

from rich import print
from rich.console import Console
console = Console()

console.print(rf" {'#'*20} TEMPLATE MATCHING WITH OPENCV {'#'*20} ", style="bold green")

def preprocess(image):
    if len(image.shape) == 3:
        gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    else:
        gray = image.copy()
    
    denoised = cv2.medianBlur(gray, 3)
    clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8, 8))
    enhanced = clahe.apply(denoised)
    normalized = cv2.normalize(enhanced, None, 0, 256, cv2.NORM_MINMAX)
    
    return normalized    


search_image_name = input('Enter Path and Name Source Image(Search): ') 
template_image_name = input('Enter Path and Name Target Image(Template): ')
threshold = float(input('Enter Threshold(float): '))

search_image = cv2.imread(search_image_name)
template_image = cv2.imread(template_image_name, cv2.IMREAD_GRAYSCALE)

search_image_gray = search_image.copy()

search_image_gray = cv2.cvtColor(search_image_gray, cv2.COLOR_BGR2GRAY)

result = cv2.matchTemplate(search_image_gray, template_image, cv2.TM_CCOEFF_NORMED)

min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
print(f"Max Value: {max_val} - Max Loc: {max_loc} / Min Value: {min_val}")

# location = np.where(result>=threshold)
template_height, template_width = template_image.shape

# for pt in zip(*location[::-1]):
#     cv2.putText(search_image, f"Max_Value: {max_val:.2f}", max_loc, 1, 0.5, (255,0,0), 2,)
#     cv2.rectangle(search_image, pt, (pt[0]+template_width, pt[1]+template_height), (0,255,0), 2)

# Show Output
cv2.putText(search_image, f"Max_Value: {max_val:.2f}", (max_loc[0], max_loc[1]-5), 1, 1, (0,255,0), 2,)
cv2.rectangle(search_image, max_loc, (max_loc[0]+template_width, max_loc[1]+template_height), (0,255,0), 2)

cv2.imwrite("./outputs/python_output.jpg", search_image)
cv2.namedWindow("Template Matching Output", cv2.WINDOW_FREERATIO)
cv2.imshow("Template Matching Output", search_image)

# Stop the program on the ESC key or 'q'
keyCode = cv2.waitKey(0) & 0xFF
if keyCode == 27 or keyCode == ord('q'):
    cv2.destroyAllWindows()
    