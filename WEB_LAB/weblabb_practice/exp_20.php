<html>
    <head><title>ELECTRICITY BILL</title>
    </head>
    <?php
   $result_str = $result = ''; 
   if (isset($_POST['unit-submit'])) { 
   $units = $_POST['units']; 
   if (!empty($units)) { 
   $result = cal_bill($units); 
   $result_str = 'Total amount of ' . $units . ' - ' . $result; 
   } 
    }
    function cal_bill($units) { 
        $cost_1 = 3.50; 
        $cost_2 = 4.00; 
        $cost_3 = 5.20; 
        $cost_4 = 6.50; 
        if($units <= 50) { 
            $bill = $units * $cost_1; 
            } 
            else if($units > 50 && $units <= 100) { 
            $temp = 50 * $cost_1; 
            $remaining_units = $units - 50; 
            $bill = $temp + ($remaining_units * $cost_2); 
            } 
            else if($units > 100 && $units <= 200) { 
            $temp = (50 * 3.5) + (100 * $cost_2); 
            $remaining_units = $units - 150; 
            $bill = $temp + ($remaining_units * $cost_3); 
            } 
            else { 
            $temp = (50 * 3.5) + (100 * $cost_2) + (100 * $cost_3); 
            $remaining_units = $units - 250; 
            $bill = $temp + ($remaining_units * $cost_4); 
            } 
            return number_format((float)$bill, 2, '.', ''); 
    }
    ?>
   <body> 
<div> 
<h1>Electricity Bill</h1> 
<form action="" method="post" id="quiz-form"> 
<input type="number" name="units" id="units" placeholder="Please enter no.of Units" /> 
<input type="submit" name="unit-submit" id="unit-submit" value="Submit"/> 
</form> 
<div> 
<?php echo '<br />' . $result_str; ?> 
</div> 
</div> 
</body> 
</html> 
