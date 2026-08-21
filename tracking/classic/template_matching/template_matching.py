import cv2
import time

from rich import print
from rich.console import Console
console = Console()
    
search_video_name = input('Enter Path and Name Source Video(Search): ') 
threshold = float(input('Enter Threshold(float): '))

window_title = "Template Matching"
window_handle = cv2.namedWindow(window_title, cv2.WINDOW_NORMAL)
cv2.setWindowProperty(window_title, cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)
        
video_capture = cv2.VideoCapture(search_video_name)
counter = 0
counter_loss = 0

if video_capture.isOpened():
    try:
        while True:
            ret_val, frame = video_capture.read()
            frame_copy = frame.copy()
            
            if counter == 0:
                cv2.namedWindow("Select Template", cv2.WINDOW_NORMAL)
                cv2.setWindowProperty("Select Template", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)
                (xmin, ymin, boxw, boxh) = cv2.selectROI("Select Template", frame)
                cv2.destroyWindow("Select Template")
                template_image = frame_copy[ymin:ymin+boxh, xmin:xmin+boxw]

            start = time.time()

            result = cv2.matchTemplate(frame, template_image, cv2.TM_CCOEFF_NORMED)
            min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)

            print(f"Max Value: {max_val} - max_loc: {max_loc} - min_loc: {min_loc}")

            end = (time.time() - start) * 1000

            # if max_val >= 0.8:
            #     console.print(rf" ***** Save Tamplate Image in Cache ***** ", style="#CFF800")
            #     template_image_t1 = template_image

            # Object Loss
            if max_val < 0.75:    
                # Show Template
                cv2.imshow("Update Template", template_image)   
                
                console.print(" ***** Object Loss ***** ", style="#FF5768")                    
                cv2.putText(frame, "Loss Object", (20, 70), 2, 0.5, (0,0,255), 2,)

                counter_loss += 1
                
                if len(template_image) == 0:
                    console.print(" !!!!! Template Image is Empty !!!!! ", style="#FF5C77")
                    break
                
                if max_val <= threshold and counter_loss >= 3:
                    console.print(" ***** Object Loss And Break ***** ", style="#FF5768")
                    break
            
            template_height, template_width,_ = template_image.shape
            
            if counter != 0 and counter % 3 == 0:
                template_image = frame_copy[max_loc[1]:max_loc[1]+template_height, max_loc[0]:max_loc[0]+template_width] # frame_copy[max_loc[1]-1:max_loc[1]+template_height, max_loc[0]-1:max_loc[0]+template_width]

                if counter % 30 == 0 and counter_loss >= 2:
                    console.print(" ***** Reset Size ***** ", style="#FFD872")
                    template_image = frame_copy[max_loc[1]-2:max_loc[1]+template_height+2, max_loc[0]-2:max_loc[0]+template_width+2]

            #display FPS
            cv2.putText(frame, f"FPS: {1000/end:.0f}", (20, 40), cv2.FONT_HERSHEY_DUPLEX, 0.7, (0,0,0), 2, cv2.LINE_AA)
            cv2.putText(frame, f"FPS: {1000/end:.0f}", (20+2, 40-2), cv2.FONT_HERSHEY_DUPLEX, 0.7, (255,255,255), 2, cv2.LINE_AA)

            # display Max_Value
            cv2.putText(frame, f"Max_Value: {max_val:.2f}", (max_loc[0], max_loc[1]-5), cv2.FONT_HERSHEY_DUPLEX, 0.75, (0,0,0), 2, cv2.LINE_AA)
            cv2.putText(frame, f"Max_Value: {max_val:.2f}", (max_loc[0]+1, max_loc[1]-6), cv2.FONT_HERSHEY_DUPLEX, 0.75, (255,255,255), 2, cv2.LINE_AA)
            
            cv2.rectangle(frame, max_loc, (max_loc[0]+template_width, max_loc[1]+template_height), (0,255,0), 2)

            counter += 1
            console.print(f" ##### Number Frame: {counter} ##### ", style="#00CDAC")

            cv2.imshow(window_title, frame)

            keyCode = cv2.waitKey(10) & 0xFF
            # Stop the program on the ESC key or 'q'
            if keyCode == 27 or keyCode == ord('q'):
                break
    finally:
        video_capture.release()
        cv2.destroyAllWindows()
else:
    print("Error: Unable to open Video")
