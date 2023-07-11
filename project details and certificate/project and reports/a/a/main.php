<?php

session_start();

if (!isset($_SESSION['username'])) {
    header("Location: index.php");
}

?>
<html lang="">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style2.css">
    <title>welcome to my first page </title>
</head>

<body>
    <h1 style="text-align:center;font-size:70px;margin-top:20px;"> TO-DO LIST </h1>
    <div class="back">
        <section id="one">
            <div class="clock">

                <div class="hour">
                    <div class="hr" id="hr"></div>
                </div>

                <div class="min">
                    <div class="mn" id="mn"></div>
                </div>

                <div class="sec">
                    <div class="sc" id="sc"></div>
                </div>
            </div>
        </section>
        <center>
            <div class="a">
                <a id="b" href="index3.php">Professional</a>
                <a id="b1" href="personal.html">Personal</a>
                <a id="b2" href="index.php">Logout</a>
            </div>
        </center>
    </div>
    <script>
        const deg = 6;
        const hr = document.querySelector('#hr');
        const mn = document.querySelector('#mn');
        const sc = document.querySelector('#sc');

        setInterval(() => {

            let day = new Date();
            let hh = day.getHours() * 30;
            let mm = day.getMinutes() * deg;
            let ss = day.getSeconds() * deg;

            hr.style.transform = `rotateZ(${(hh)+(mm/12)}deg)`;
            mn.style.transform = `rotateZ(${mm}deg)`;
            sc.style.transform = `rotateZ(${ss}deg)`;

        })
    </script>


</body>

</html>