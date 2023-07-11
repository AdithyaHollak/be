package com.example.quora.Model;

public class Post {
    private String askedby,date,postid,publisher,question,questionImage,topic;
public Post() {
}
    public Post(String askedby, String date, String postid, String publisher, String question, String questionImage, String topic) {
        this.askedby = askedby;
        this.date = date;
        this.postid = postid;
        this.publisher = publisher;
        this.question = question;
        this.questionImage = questionImage;
        this.topic = topic;
    }

    public String getAskedby() {
        return askedby;
    }

    public String getDate() {
        return date;
    }

    public String getPostid() {
        return postid;
    }

    public String getPublisher() {
        return publisher;
    }

    public String getQuestion() {
        return question;
    }

    public String getQuestionimage() {
        return questionImage;
    }

    public String getTopic() {
        return topic;
    }
}
