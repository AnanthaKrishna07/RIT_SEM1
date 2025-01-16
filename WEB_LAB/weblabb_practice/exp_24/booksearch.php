<?php 
require "bookconnect.php"; 
if(isset($_POST['sub'])) 
{ $bookhead=$_POST['btitle']; 
$store = "SELECT * FROM `books` WHERE `title` = '$bookhead'"; 
$result=$conn->query($store); 
if($result=mysqli_query($conn,$store)) 
{ 
while($query_execute=mysqli_fetch_assoc($result)) 
{ 
?><table border="1"><tr><th>sino</th><th>title</th><th>author</th><th>edition</th><th>publisher</th></tr> 
<tr><td><?php echo $query_execute["ano"];?></td> 
<td><?php echo $query_execute["title"];?></td> 
<td><?php echo $query_execute["author"];?></td> 
<td><?php echo $query_execute["edition"];?></td> 
<td><?php echo $query_execute["publisher"];?></td></tr></table> 
<?php } 
}$con->close(); 
} 
?> 
<html> 
<head> 
<title>book search</title> 
</head> 
<body><form method="POST" action=""> 
<label>enter the title</label>
<input type="text" name="btitle"> 
<input type="submit" name="sub" value="submit"> 
<a href="insert.php" >ADD DATA</a> 
</form> 
</body> 
</html>
