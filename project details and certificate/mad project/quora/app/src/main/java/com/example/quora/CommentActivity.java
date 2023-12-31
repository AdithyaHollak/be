package com.example.quora;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.bumptech.glide.Glide;
import com.example.quora.Adapters.CommentAdapter;
import com.example.quora.Model.Comment;
import com.example.quora.Model.User;
import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;

import de.hdodenhof.circleimageview.CircleImageView;

public class CommentActivity extends AppCompatActivity {
    private Toolbar toolbar;
    private RecyclerView recyclerView;
    private CircleImageView circleImageView;
    private TextView textView;
    private EditText editText;

    private ProgressDialog loader;
    String postid;

    private CommentAdapter commentAdapter;
    private List<Comment> commentList;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_comment);

        toolbar=findViewById(R.id.home_toolbar);
        setSupportActionBar(toolbar);
        getSupportActionBar().setTitle("Comments");

        Intent intent = getIntent();
        postid = intent.getStringExtra("postid");


        recyclerView = findViewById(R.id.recyclerView);
        circleImageView = findViewById(R.id.comment_profile_image);
        textView = findViewById(R.id.commenting_post_textview);
        editText =findViewById(R.id.add_comment);
        loader = new ProgressDialog(this);

        textView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String commentText = editText.getText().toString();
                if(TextUtils.isEmpty(commentText)){
                    editText.setError("Please type something");

                }
                else{
                    addComment();
                }
            }
        });
        recyclerView = findViewById(R.id.recyclerView);
        LinearLayoutManager linearLayoutManager=new LinearLayoutManager(this);
        linearLayoutManager.setReverseLayout(true);
        linearLayoutManager.setStackFromEnd(true);
        recyclerView.setHasFixedSize(true);
        recyclerView.setLayoutManager(linearLayoutManager);

        commentList = new ArrayList<>();
        commentAdapter = new CommentAdapter(CommentActivity.this, commentList, postid);
        recyclerView.setAdapter(commentAdapter);
        getImage();
        readComments();
    }

    private void readComments() {
        DatabaseReference reference = FirebaseDatabase.getInstance().getReference("comments").child(postid);
        reference.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                commentList.clear();
                for(DataSnapshot dataSnapshot : snapshot.getChildren()){
                    Comment comment = dataSnapshot.getValue(Comment.class);
                    commentList.add(comment);
                }
                commentAdapter.notifyDataSetChanged();
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {

            }
        });
    }

    private void addComment() {
        loader.setMessage("Adding a comment");
        loader.setCanceledOnTouchOutside(false);
        loader.show();

        DatabaseReference reference = FirebaseDatabase.getInstance().getReference("comments").child(postid);
        String commentid = reference.push().getKey();
        String date = DateFormat.getDateInstance().format(new Date());

        HashMap<String, Object> hashMap = new HashMap<>();
        hashMap.put("comment",editText.getText().toString());
        hashMap.put("publisher", FirebaseAuth.getInstance().getCurrentUser().getUid());
        hashMap.put("commentid", commentid);
        hashMap.put("postid", postid);
        hashMap.put("date", date);

        reference.child(commentid).setValue(hashMap).addOnCompleteListener(new OnCompleteListener<Void>() {
            @Override
            public void onComplete(@NonNull Task<Void> task) {
                if(task.isSuccessful()){
                    Toast.makeText(CommentActivity.this, "comment added successfully", Toast.LENGTH_SHORT).show();
                }else
                {
                    Toast.makeText(CommentActivity.this, "Error adding comment"+task.getException(), Toast.LENGTH_SHORT).show();
                }
                loader.dismiss();
                editText.setText("");
            }
        });
    }
    private void getImage(){
        DatabaseReference reference = FirebaseDatabase.getInstance().getReference("users").child(FirebaseAuth.getInstance().getCurrentUser().getUid());
        reference.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                User user = snapshot.getValue(User.class);
                Glide.with(CommentActivity.this).load(user.getProfileimageurl()).into(circleImageView);
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                Toast.makeText(CommentActivity.this, error.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });

    }
}