<?php 
$mysql_host='localhost'; 
$mysql_user='2281mca'; 
$mysql_password='2547'; 
$conn=mysqli_connect($mysql_host,$mysql_user,$mysql_password); 
if(mysqli_select_db($conn,'22mca007')) 
{echo 'connection successful'; 
} 
else{ 
echo 'connection failed'; 
} 
?>
