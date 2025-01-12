<html> 
<body> 
<h1>Registration form</h1> 
<form action = "" method = "POST"> 
Username : <input type="text" name="username"><br> <br> 
Email : <input type="text" name="email"><br> <br> 
Password : <input type="text" name="pass"><br> <br> 
Confirm password : <input type="text" name="cpass"><br> <br> 
<input type="submit" value="Register"> 
 
<?php 
if (empty($_POST['username']) || 
empty($_POST['pass']) || 
empty($_POST['email']) || 
empty($_POST['cpass'])) 
{ 
die("<script>alert('Please fill all required fields!')</script>"); 
} 
if ($_POST['pass'] != $_POST['cpass']) 
{ 
die ('<script>alert("Password and confirm password should match")</script>'); 
}
if(strpos($_POST['email'],'@gmail.com')==false) {
    die("<script>alert('invalid email')</script>");
}
if(strlen($_POST['pass'])<8||strlen($_POST['pass'])<8){
    die("<script>alert('password must be 8 character')</script>");
}
else 
{ 
die("successfull"); 
} 
?> 
</form> 
</body> 
</html> 
