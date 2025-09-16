<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Your Order Receipt</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@400;600&family=Pacifico&display=swap');

        body {
            font-family: 'Poppins', sans-serif;
            background-color: #fdf6f7;
            color: #4a4a4a;
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            margin: 0;
            padding: 20px;
        }

        .receipt-box {
            background: #ffffff;
            padding: 40px;
            border-radius: 20px;
            box-shadow: 0 8px 30px rgba(212, 175, 155, 0.3);
            width: 100%;
            max-width: 400px;
            text-align: center;
        }

        h1 {
            font-family: 'Pacifico', cursive;
            color: #e57373;
            font-size: 2.5em;
            margin: 0 0 10px 0;
        }
        
        .header-info {
            font-size: 1.1em; /* Made slightly larger for the greeting */
            color: #a1887f;
            margin-bottom: 25px;
            border-bottom: 2px solid #fce4ec;
            padding-bottom: 20px;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            text-align: left;
            margin-bottom: 25px;
        }

        th, td {
            padding: 10px 5px;
            border-bottom: 1px dashed #fce4ec;
        }

        th {
            font-weight: 600;
            color: #a1887f;
            font-size: 0.9em;
        }

        .summary-row td {
            font-weight: 600;
            border-top: 2px dashed #e57373;
            padding-top: 10px;
        }
        
        .total-row td {
             font-size: 1.2em;
             color: #e57373;
        }

        .text-right { text-align: right; }

        .footer {
            margin-top: 30px;
            font-size: 0.9em;
            color: #757575;
        }
        .footer p { margin: 5px 0; }
        
        .order-again-btn {
            display: inline-block;
            width: 100%;
            box-sizing: border-box;
            background-color: #e57373;
            color: white;
            padding: 15px;
            border: none;
            border-radius: 10px;
            font-size: 1.1em;
            font-weight: 600;
            cursor: pointer;
            text-decoration: none;
            transition: background-color 0.3s;
            margin-top: 20px;
        }

        .order-again-btn:hover {
            background-color: #d32f2f;
        }
    </style>
</head>
<body>

<div class="receipt-box">
    
    <?php
    date_default_timezone_set('Asia/Bangkok');
    $menu = [
        'pizza_m margarita'   => ['name' => 'Mee-ow Margarita', 'price' => 12.00],
        'pizza_parma_ham'   => ['name' => 'Paw-ma Ham & Cheese', 'price' => 14.00],
        'pizza_hawaiian'    => ['name' => 'Hiss-waiian Tropical', 'price' => 13.50],
        'pizza_four_cheese' => ['name' => 'Four-Paw Cheese Delight', 'price' => 13.00],
        'pizza_pepperoni'   => ['name' => 'Purr-peroni Feast', 'price' => 14.00],
        'jelly_amount'      => ['name' => 'Red Jelly with Cream', 'price' => 4.00],
        'drink_milk'        => ['name' => 'Kitty Milk', 'price' => 2.50],
        'drink_soda'        => ['name' => 'Salmon Splash Soda', 'price' => 3.00],
        'drink_tea'         => ['name' => 'Tuna Tonic Iced Tea', 'price' => 3.00],
        'drink_fizz'        => ['name' => 'Furball Fizz Water', 'price' => 2.00],
    ];
    $ordered_items = [];
    $subtotal = 0;
    foreach ($menu as $field_name => $item) {
        if (isset($_POST[$field_name]) && (int)$_POST[$field_name] > 0) {
            $quantity = (int)$_POST[$field_name];
            $item_total = $quantity * $item['price'];
            $ordered_items[] = ['name' => $item['name'], 'quantity' => $quantity, 'total' => $item_total];
            $subtotal += $item_total;
        }
    }
    $vat_amount = $subtotal * 0.07;
    $total_net = $subtotal + $vat_amount;
    $order_time = time();
    $delivery_timestamp = $order_time + (30 * 60);

    // --- New Time-Based Greeting Logic ---
    $current_hour = (int)date('H', $order_time);
    $time_based_greeting = '';

    if ($current_hour < 11) { // Before 11 AM is breakfast
        $time_based_greeting = '🌅 Enjoy your breakfast!';
    } elseif ($current_hour < 17) { // 11 AM to 5 PM (16:59) is lunch
        $time_based_greeting = '☀️ Enjoy your lunch!';
    } else { // 5 PM (17:00) onwards is dinner
        $time_based_greeting = '🌙 Enjoy your dinner!';
    }
    ?>

    <h1>Thank You!</h1>
    <div class="header-info">
        <?php echo $time_based_greeting; ?>
    </div>

    <table>
        <thead>
            <tr>
                <th>Item</th>
                <th>Qty</th>
                <th class="text-right">Total</th>
            </tr>
        </thead>
        <tbody>
            <?php if (empty($ordered_items)): ?>
                <tr>
                    <td colspan="3">You did not order any items.</td>
                </tr>
            <?php else: ?>
                <?php foreach ($ordered_items as $item): ?>
                    <tr>
                        <td><?php echo $item['name']; ?></td>
                        <td style="text-align: center;"><?php echo $item['quantity']; ?></td>
                        <td class="text-right">$<?php echo number_format($item['total'], 2); ?></td>
                    </tr>
                <?php endforeach; ?>
            <?php endif; ?>

            <tr class="summary-row">
                <td colspan="2">Subtotal</td>
                <td class="text-right">$<?php echo number_format($subtotal, 2); ?></td>
            </tr>
            <tr>
                <td colspan="2">VAT (7%)</td>
                <td class="text-right">$<?php echo number_format($vat_amount, 2); ?></td>
            </tr>
            <tr class="summary-row total-row">
                <td colspan="2">Total Net</td>
                <td class="text-right">$<?php echo number_format($total_net, 2); ?></td>
            </tr>
        </tbody>
    </table>

    <div class="footer">
        <p><strong>Order Time:</strong> <?php echo date('H:i', $order_time); ?></p>
        <p><strong>Estimated Delivery:</strong> <?php echo date('H:i', $delivery_timestamp); ?></p>
        <p>For questions, call us at <strong>1548</strong></p>
        <a href="foodform.htm" class="order-again-btn">Order Again</a>
    </div>
</div>

</body>
</html>