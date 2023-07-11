<?php
$title=$_POST['title'];
$completionday=$_POST['completionday'];
$completiontime=$_POST['completiontime'];

include 'database.php';
$sql="INSERT INTO todos(title, completionday,completiontime)VALUES('$title','$completionday','$completiontime')";

$result=mysqli_query($conn, $sql);

if($result){
    header("location: ./index3.php");
}
else{
    echo "Sorry We Can't Connect";
}
?>