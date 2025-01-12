<?php 
session_start();  
include('db.php'); 
 
if (isset($_SESSION['user_id'])) { 
    header("Location: dash.php"); // Redirect to dashboard if already logged in 
    exit(); 
} 
 
if (isset($_POST['submit'])) { 
    $email = $_POST['email']; 
    $password = $_POST['password']; 
 
    $sql = "SELECT * FROM students WHERE email = '$email'"; 
    $result = $conn->query($sql); 
 
    if ($result->num_rows > 0) { 
        $user = $result->fetch_assoc(); 
 
        if (password_verify($password, $user['password'])) { 
             
            $_SESSION['user_id'] = $user['id']; 
            $_SESSION['email'] = $user['email']; 
            header("Location: dash.php"); 
            exit(); 
        } else { 
            echo "Incorrect password."; 
        } 
    } else { 
        echo "No user found with that email."; 
    } 
} 
?>
<html> 
<head> 
    <title>Login</title> 
</head> 
<body> 
    <h2>Login</h2> 
    <form method="POST" action="login.php"> 
        <label>Email: </label><br> 
        <input type="email" name="email" required><br><br> 
         
        <label>Password: </label><br> 
        <input type="password" name="password" required><br><br> 
         
        <input type="submit" name="submit" value="Login"> 
    </form> 
</body> 
</html> 