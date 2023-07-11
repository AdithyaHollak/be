# -*- coding: utf-8 -*-
"""
Created on Tue Jun 22 21:13:19 2021

@author: chsat
"""

import cv2
import numpy as np
from keras.models import Sequential
from keras.layers import Dense, Dropout, Flatten
from keras.layers import Conv2D
from keras.layers import MaxPooling2D



video_capture = cv2.VideoCapture(0)
faceCascade = cv2.CascadeClassifier('style.xml')
video_capture.set(3, 480) #frame width
video_capture.set(4, 640) #frame height
MODEL_MEAN_VALUES = (78.4263377603, 87.7689143744, 114.895847746)
age_list = ['(0, 2)', '(4, 6)', '(8, 12)', '(15, 20)', '(21, 28)', '(38, 43)', '(48, 53)', '(60, 100)']
gender_list = ['Male', 'Female']
emotion_dict = {0: " Angry ", 1: "Disgusted", 2: " Fearful ", 3: " Happy ", 4: " Neutral ", 5: " Sad ", 6: "Surprised"}


def load_caffe_models():
    age_net = cv2.dnn.readNetFromCaffe('deploy_age.prototxt', 'age_net.caffemodel')
    gender_net = cv2.dnn.readNetFromCaffe('deploy_gender.prototxt', 'gender_net.caffemodel')
    return(age_net, gender_net)

def load_emotion_model():
    emotion_model = Sequential()
    emotion_model.add(Conv2D(32, kernel_size=(3, 3), activation='relu', input_shape=(48,48,1)))
    emotion_model.add(Conv2D(64, kernel_size=(3, 3), activation='relu'))
    emotion_model.add(MaxPooling2D(pool_size=(2, 2)))
    emotion_model.add(Dropout(0.25))
    emotion_model.add(Conv2D(128, kernel_size=(3, 3), activation='relu'))
    emotion_model.add(MaxPooling2D(pool_size=(2, 2)))
    emotion_model.add(Conv2D(128, kernel_size=(3, 3), activation='relu'))
    emotion_model.add(MaxPooling2D(pool_size=(2, 2)))
    emotion_model.add(Dropout(0.25))
    emotion_model.add(Flatten())
    emotion_model.add(Dense(1024, activation='relu'))
    emotion_model.add(Dropout(0.5))
    emotion_model.add(Dense(7, activation='softmax'))
    emotion_model.load_weights('model.h5')
    cv2.ocl.setUseOpenCL(False)
    return emotion_model
    
def video_detector(age_net,gender_net,emotion_net):
    font = cv2.FONT_HERSHEY_TRIPLEX #Type of font
    while True:
        check,frame = video_capture.read()#returns if the capture was successful and the frame
        frame=cv2.flip(frame,1)
        gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) #converted to greyscale
        faces = faceCascade.detectMultiScale(frame, 1.2,10,cv2.CASCADE_SCALE_IMAGE,(30,30))
        #faces_gray = faceCascade.detectMultiScale(gray, 1.2,10,cv2.CASCADE_SCALE_IMAGE,(30,30))
        print(check) #to check if frame has a face
        print(frame) #printing the frame
        for (x, y, w, h) in faces:
            #Make rectangle on face
            #print(x,y,w,h)#print The coordinates of face
            cv2.rectangle(frame, (x, y), (x + w, y + h), (255,255,0), 2)
            # Get Face as Matrix and copy it
            face_img = frame[y:y + h, h:h + w].copy()
            #print(face_img)
            blob=cv2.dnn.blobFromImage(face_img,1,(227,227),MODEL_MEAN_VALUES,swapRB=False)
            # Predict Gender
            gender_net.setInput(blob)
            gender_preds = gender_net.forward()
            gender = gender_list[gender_preds[0].argmax()]
            # Predict Age
            age_net.setInput(blob)
            age_preds = age_net.forward()
            age = age_list[age_preds[0].argmax()]
            #predict emotion
            roi_gray_frame = gray_frame[y:y + h, x:x + w]
            cropped_img = np.expand_dims(np.expand_dims(cv2.resize(roi_gray_frame, (48, 48)), -1), 0)
            prediction = emotion_net.predict(cropped_img)
            maxindex = int(np.argmax(prediction))
            emotion=emotion_dict[maxindex]
            

            
           
            
            overlay_text = "%s %s %s" % (gender, age, emotion)
            cv2.putText(frame, overlay_text, (x, y), font, 1, (34, 139, 34), 2, cv2.LINE_AA)
            cv2.imshow('frame', frame)
        key=cv2.waitKey(1)
        if key == 27:
            break
    video_capture.release()
    cv2.destroyAllWindows()

def main():
    age_net, gender_net = load_caffe_models()# load caffe models (age & gender)
    emotion_net=load_emotion_model()
    video_detector(age_net, gender_net,emotion_net)  # prediction age & gender

if __name__ == "__main__":
    main()



