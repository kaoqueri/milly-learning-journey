<?php
// --- PHP LOGIC ---
$bmi_result = null;
$bmi_category = '';
$category_color = '#000'; // Default text color
$error_message = '';

if (isset($_POST['w']) && isset($_POST['h'])) {
    $weight = (float)$_POST['w']; // Weight in kg
    $height = (float)$_POST['h']; // Height in meters

    if ($weight <= 0 || $height <= 0) {
        $error_message = "Please enter positive values for weight and height.";
    } else {
        // Calculate BMI: weight (kg) / [height (m)]^2
        $bmi = $weight / ($height * $height);
        $bmi_result = number_format($bmi, 2);

        // Determine BMI category
        if ($bmi < 18.5) {
            $bmi_category = "Underweight";
            $category_color = "#3498db"; // Blue
        } elseif ($bmi >= 18.5 && $bmi < 25) {
            $bmi_category = "Normal Weight";
            $category_color = "#2ecc71"; // Green
        } elseif ($bmi >= 25 && $bmi < 30) {
            $bmi_category = "Overweight";
            $category_color = "#f39c12"; // Orange
        } else {
            $bmi_category = "Obesity";
            $category_color = "#e74c3c"; // Red
        }
    }
} else {
    $error_message = "Please fill in both weight and height.";
}
?>
<!DOCTYPE html>
<html>
<head>
    <title>Your BMI Result 🐾</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@400;600;700&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: 'Poppins', sans-serif;
            background-color: #FFF3E0; /* Creamy background */
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            margin: 0;
        }
        .result-box {
            background-color: #ffffff;
            padding: 40px;
            border-radius: 20px;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
            text-align: center;
            width: 320px;
        }
        h2 {
            color: #4A4A4A;
            margin-top: 0;
            margin-bottom: 15px;
            font-weight: 600;
        }
        .bmi-value {
            font-size: 48px;
            font-weight: 700;
            color: #4A4A4A;
            margin: 10px 0;
        }
        .bmi-category {
            font-size: 20px;
            font-weight: 600;
            margin-top: 5px;
            margin-bottom: 30px;
        }
        .error {
            color: #e74c3c;
            font-weight: 600;
            margin-bottom: 30px;
        }
        a {
            background-color: #ff9900;
            color: white;
            border: none;
            padding: 12px 25px;
            border-radius: 10px;
            cursor: pointer;
            font-weight: 600;
            font-size: 16px;
            text-decoration: none;
            display: inline-block;
            transition: all 0.3s ease;
        }
        a:hover {
            background-color: #e68a00;
            transform: translateY(-3px);
            box-shadow: 0 6px 15px rgba(255, 153, 0, 0.4);
        }
    </style>
</head>
<body>

<div class="result-box">
    <h2>Your Result</h2>

    <?php if ($error_message): ?>
        <p class="error"><?php echo $error_message; ?></p>
    <?php else: ?>
        <p class="bmi-value"><?php echo $bmi_result; ?></p>
        <p class="bmi-category" style="color: <?php echo $category_color; ?>;">
            <?php echo $bmi_category; ?>
        </p>
    <?php endif; ?>
    
    <a href="bmiform.htm">Calculate Again</a>
</div>

</body>
</html>