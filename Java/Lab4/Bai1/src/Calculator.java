import java.util.ArrayList;
public class Calculator extends javax.swing.JFrame {

    public Calculator() {
        initComponents();
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        outputLabel = new javax.swing.JLabel();
        numberLabel = new javax.swing.JPanel();
        number7 = new javax.swing.JButton();
        number8 = new javax.swing.JButton();
        number9 = new javax.swing.JButton();
        division = new javax.swing.JButton();
        number4 = new javax.swing.JButton();
        number5 = new javax.swing.JButton();
        number6 = new javax.swing.JButton();
        multiple = new javax.swing.JButton();
        number1 = new javax.swing.JButton();
        number2 = new javax.swing.JButton();
        number3 = new javax.swing.JButton();
        difference = new javax.swing.JButton();
        clear = new javax.swing.JButton();
        number0 = new javax.swing.JButton();
        answer = new javax.swing.JButton();
        addition = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Calculator");
        setResizable(false);

        outputLabel.setFont(new java.awt.Font("Tahoma", 0, 36)); // NOI18N
        outputLabel.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        outputLabel.setText("0");
        outputLabel.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0), 2));

        numberLabel.setLayout(new java.awt.GridLayout(4, 4, 2, 2));

        number7.setBackground(new java.awt.Color(102, 102, 102));
        number7.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number7.setForeground(new java.awt.Color(255, 255, 255));
        number7.setText("7");
        number7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number7ActionPerformed(evt);
            }
        });
        numberLabel.add(number7);

        number8.setBackground(new java.awt.Color(102, 102, 102));
        number8.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number8.setForeground(new java.awt.Color(255, 255, 255));
        number8.setText("8");
        number8.setOpaque(true);
        number8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number8ActionPerformed(evt);
            }
        });
        numberLabel.add(number8);

        number9.setBackground(new java.awt.Color(102, 102, 102));
        number9.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number9.setForeground(new java.awt.Color(255, 255, 255));
        number9.setText("9");
        number9.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number9ActionPerformed(evt);
            }
        });
        numberLabel.add(number9);

        division.setBackground(new java.awt.Color(255, 255, 102));
        division.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        division.setText("/");
        division.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                divisionActionPerformed(evt);
            }
        });
        numberLabel.add(division);

        number4.setBackground(new java.awt.Color(102, 102, 102));
        number4.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number4.setForeground(new java.awt.Color(255, 255, 255));
        number4.setText("4");
        number4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number4ActionPerformed(evt);
            }
        });
        numberLabel.add(number4);

        number5.setBackground(new java.awt.Color(102, 102, 102));
        number5.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number5.setForeground(new java.awt.Color(255, 255, 255));
        number5.setText("5");
        number5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number5ActionPerformed(evt);
            }
        });
        numberLabel.add(number5);

        number6.setBackground(new java.awt.Color(102, 102, 102));
        number6.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number6.setForeground(new java.awt.Color(255, 255, 255));
        number6.setText("6");
        number6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number6ActionPerformed(evt);
            }
        });
        numberLabel.add(number6);

        multiple.setBackground(new java.awt.Color(255, 255, 102));
        multiple.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        multiple.setText("X");
        multiple.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                multipleActionPerformed(evt);
            }
        });
        numberLabel.add(multiple);

        number1.setBackground(new java.awt.Color(102, 102, 102));
        number1.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number1.setForeground(new java.awt.Color(255, 255, 255));
        number1.setText("1");
        number1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number1ActionPerformed(evt);
            }
        });
        numberLabel.add(number1);

        number2.setBackground(new java.awt.Color(102, 102, 102));
        number2.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number2.setForeground(new java.awt.Color(255, 255, 255));
        number2.setText("2");
        number2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number2ActionPerformed(evt);
            }
        });
        numberLabel.add(number2);

        number3.setBackground(new java.awt.Color(102, 102, 102));
        number3.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number3.setForeground(new java.awt.Color(255, 255, 255));
        number3.setText("3");
        number3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number3ActionPerformed(evt);
            }
        });
        numberLabel.add(number3);

        difference.setBackground(new java.awt.Color(255, 255, 102));
        difference.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        difference.setText("-");
        difference.setToolTipText("");
        difference.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                differenceActionPerformed(evt);
            }
        });
        numberLabel.add(difference);

        clear.setBackground(new java.awt.Color(255, 255, 102));
        clear.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        clear.setText("C");
        clear.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                clearActionPerformed(evt);
            }
        });
        numberLabel.add(clear);

        number0.setBackground(new java.awt.Color(102, 102, 102));
        number0.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        number0.setForeground(new java.awt.Color(255, 255, 255));
        number0.setText("0");
        number0.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                number0ActionPerformed(evt);
            }
        });
        numberLabel.add(number0);

        answer.setBackground(new java.awt.Color(255, 255, 102));
        answer.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        answer.setText("=");
        answer.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                answerActionPerformed(evt);
            }
        });
        numberLabel.add(answer);

        addition.setBackground(new java.awt.Color(255, 255, 102));
        addition.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        addition.setText("+");
        addition.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                additionActionPerformed(evt);
            }
        });
        numberLabel.add(addition);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(numberLabel, javax.swing.GroupLayout.DEFAULT_SIZE, 438, Short.MAX_VALUE)
                    .addComponent(outputLabel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(outputLabel, javax.swing.GroupLayout.PREFERRED_SIZE, 70, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(numberLabel, javax.swing.GroupLayout.DEFAULT_SIZE, 412, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void number0ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number0ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number0.getText());
        }
    }//GEN-LAST:event_number0ActionPerformed

    private void number1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number1ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number1.getText());
        }
    }//GEN-LAST:event_number1ActionPerformed

    private void number2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number2ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number2.getText());
        }
    }//GEN-LAST:event_number2ActionPerformed

    private void number3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number3ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number3.getText());
        }
    }//GEN-LAST:event_number3ActionPerformed

    private void number4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number4ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number4.getText());
        }
    }//GEN-LAST:event_number4ActionPerformed

    private void number5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number5ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number5.getText());
        }
    }//GEN-LAST:event_number5ActionPerformed

    private void number6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number6ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number6.getText());
        }
    }//GEN-LAST:event_number6ActionPerformed

    private void number7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number7ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number7.getText());
        }
    }//GEN-LAST:event_number7ActionPerformed

    private void number8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number8ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number8.getText());
        }
    }//GEN-LAST:event_number8ActionPerformed

    private void number9ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_number9ActionPerformed
        String value = this.outputLabel.getText();
        if (value.length() < 10)
        {
            if (value.equals("0")) value = "";
            this.outputLabel.setText(value + number9.getText());
        }
    }//GEN-LAST:event_number9ActionPerformed

    private void additionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_additionActionPerformed
        calculationAction();
        this.calculation = "+";
        if (this.outputLabel.getText().equals("")) num1 += Double.parseDouble(this.outputLabel.getText());
        outputLabel.setText("0");
    }//GEN-LAST:event_additionActionPerformed

    private void differenceActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_differenceActionPerformed
        calculationAction();
        this.calculation = "-";
        outputLabel.setText("0");
    }//GEN-LAST:event_differenceActionPerformed

    private void multipleActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_multipleActionPerformed
        calculationAction();
        this.calculation = "x";
        outputLabel.setText("0");
    }//GEN-LAST:event_multipleActionPerformed

    private void divisionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_divisionActionPerformed
        calculationAction();
        this.calculation = "/";
        outputLabel.setText("0");
    }//GEN-LAST:event_divisionActionPerformed

    private void clearActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_clearActionPerformed
        this.outputLabel.setText("0");
        this.calculation = "";
        this.result = 0;
        this.num1 = 0;
    }//GEN-LAST:event_clearActionPerformed

    private void answerActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_answerActionPerformed
        calculationAction();
        if (Double.toString(result).endsWith(".0"))
        {
            this.outputLabel.setText(Double.toString(this.result).replace(".0", ""));
        }
        else
        {
            this.outputLabel.setText(Double.toString(this.result));
        }
        num1 = this.result;
    }//GEN-LAST:event_answerActionPerformed

    private void calculationAction()
    {
        if (this.calculation.equals(""))
        {
            num1 = Double.parseDouble(this.outputLabel.getText());
        }
        else
        {
            if (this.calculation.equals("+")) this.result = num1 + Double.parseDouble(this.outputLabel.getText());
            if (this.calculation.equals("-")) this.result = num1 - Double.parseDouble(this.outputLabel.getText());
            if (this.calculation.equals("x")) this.result = num1 * Double.parseDouble(this.outputLabel.getText());
            if (this.calculation.equals("/")) this.result = num1 / Double.parseDouble(this.outputLabel.getText());
        }
    }
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Calculator().setVisible(true);
            }
        });
    }
    private double result = 0, num1 = 0;
    private String calculation = "";
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton addition;
    private javax.swing.JButton answer;
    private javax.swing.JButton clear;
    private javax.swing.JButton difference;
    private javax.swing.JButton division;
    private javax.swing.JButton multiple;
    private javax.swing.JButton number0;
    private javax.swing.JButton number1;
    private javax.swing.JButton number2;
    private javax.swing.JButton number3;
    private javax.swing.JButton number4;
    private javax.swing.JButton number5;
    private javax.swing.JButton number6;
    private javax.swing.JButton number7;
    private javax.swing.JButton number8;
    private javax.swing.JButton number9;
    private javax.swing.JPanel numberLabel;
    private javax.swing.JLabel outputLabel;
    // End of variables declaration//GEN-END:variables
}
