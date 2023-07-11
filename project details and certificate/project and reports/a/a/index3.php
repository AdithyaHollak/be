<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-giJF6kkoqNQ00vy+HMDP7azOuL0xtbfIcaT9wjKHr8RbDVddVHyTfAAsrekwKmP1" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
    <style> .body{ 
    background-size:cover
    } 

    .container-fluid{
                font-family: Poppins;
                margin:0;
                padding:0;
                background-color: white;
              }
            .navbar{
                border-radius: 0;
                border:none;
                padding: 2.5vh 1.5vw;
                margin-bottom: 0;
                
            }
            .nav-link{
                display:block;
                font-size: 3vh;
                padding: 1.5vh 2vw;
            }
            .nav-link:hover{
                color: green;
            }
         </style>
     <title>ToDo'S List App!</title>
     </head>
     <body>
     <div class="container-fluid">
        <nav class="navbar navbar-expand-md navbar-dark bg-dark">
         <a class="navbar-brand" href="#">TO-DO-LIST</a>  
         <span class="navbar-toggler-icon"></span>
         </button>
         <div class="collapse navbar-collapse justify-content-end" id="nav1">
         <ul class="nav navbar-nav">
         <li><a class="nav-link px-2" href='#'>Professional</a></li>
         <li><a class="nav-link px-2" href='main.php'>Logout</a></li>
         <li><a class="nav-link px-2" href='i.html'>Remainder</a></li>
         </ul>
         </div>
        </nav>

    <h1 style ="color:blue" class="text-center py-4 my-4" >ToDo'S List App</h1>
    <div class="w-50 m-auto">
    <form action="data.php" method="post" autocomplete="off">
        <div class="form-group">
            <label style ="color:white; font-size:25px" for="title">Title</label>
            <input class="form-control" type="text" name="title" id="title" placeholder="Type Here To Add On ToDo'S"  Required>
            <input class="form-control" type="text" name="completionday" id="completionday" placeholder="Add day  to complete"  Required>
            <input class="form-control" type="text" name="completiontime" id="completiontime" placeholder="Add time to complete"  Required>
        </div><br>
        <button class="btn btn-success" >Add To ToDo'S</button>
    </form>
    </div><br>
    <hr class="bg-dark w-50 m-auto">
    <div class="lists w-50 m-auto my-4">
        <h1  style="background-color:red">Your Lists</h1>
        <div id="lists">
        <table class="table table-dark table-hover">
  <thead>
    <tr>
      <th scope="col" name="id">S.no</th>
      <th scope="col">ToDo List</th>
      <th>Time</th>
      <th>Date</th>
      <th>Completion Day</th>
      <th>Completion time </th>
      <th>Action</th>
    </tr>
  </thead>
  <tbody>
  <?php
        include 'database.php';
        $sql="SELECT * FROM todos";
        $result=mysqli_query($conn, $sql);
        if($result){
            while($row=mysqli_fetch_assoc($result)){
                $id=$row['id'];
                $time =$row['time'];  
                $date =$row['date'];
                $title=$row['title'];
                $completionday=$row['completionday'];
                $completiontime=$row['completiontime'];
                ?>
                <tr>
                    <td><?php echo $id ?></td>
                    <td><?php echo $title ?></td>
                    <td><?php echo $time ?></td>
                    <td><?php echo $date ?></td>
                    <td><?php echo $completionday ?></td>
                    <td><?php echo $completiontime ?></td>

      
                    <td>
                    <a class="btn btn-success btn-sm" href="edit.php?id=<?php echo $id ?>" role="button">Edit</a>
                    <a class="btn btn-danger btn-sm" href="delete.php?id=<?php echo $id ?>" role="button">Delete</a>
 
                    </td>   
                </tr>
                <?php 
            }
        }
    ?>  
  </tbody>
</table>
        </div>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta1/dist/js/bootstrap.bundle.min.js" integrity="sha384-ygbV9kiqUc6oa4msXn9868pTtWMgiQaeYH7/t7LECLbyPA2x65Kgf80OJFdroafW" crossorigin="anonymous"></script>   
}
</script>
  </body>
</html>