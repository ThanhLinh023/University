package cau2;
import javax.swing.*;
import java.sql.*;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class datLichKham extends javax.swing.JFrame {
    public datLichKham() {
        initComponents();
        this.setLocationRelativeTo(null);
        this.setVisible(true);
        hienBacSi();
    }
    public void hienBacSi()
    {
       try 
       {
           Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "c##java_lab5", "123456");
           Statement sql = con.createStatement();
           ResultSet tenBSiRS = sql.executeQuery("SELECT TENBS FROM BACSI");
           while (tenBSiRS.next())
           {
               String name = tenBSiRS.getString("TENBS");
               tenBS.addItem(name);
           }
           con.close();
       }
       catch(Exception e)
       {
           e.getMessage();
       }
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        maBNTF = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        tenBNTF = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        ngayKhamTF = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        yeuCauTF = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        tenBS = new javax.swing.JComboBox<>();
        datLich = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Đặt lịch khám");

        jLabel1.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel1.setText("Mã bệnh nhân");

        maBNTF.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        maBNTF.setText("Mã bệnh nhân");
        maBNTF.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                maBNTFFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                maBNTFFocusLost(evt);
            }
        });
        maBNTF.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                maBNTFActionPerformed(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel2.setText("Tên bệnh nhân");

        tenBNTF.setEditable(false);
        tenBNTF.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tenBNTF.setText("Tên bệnh nhân");

        jLabel3.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel3.setText("Ngày khám");

        ngayKhamTF.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        ngayKhamTF.setText("dd-mm-yyyy");
        ngayKhamTF.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                ngayKhamTFFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                ngayKhamTFFocusLost(evt);
            }
        });
        ngayKhamTF.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ngayKhamTFActionPerformed(evt);
            }
        });

        jLabel4.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel4.setText("Yêu cầu khám");

        yeuCauTF.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        yeuCauTF.setText("Yêu cầu khám");
        yeuCauTF.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                yeuCauTFFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                yeuCauTFFocusLost(evt);
            }
        });

        jLabel5.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel5.setText("Bác sĩ khám");

        tenBS.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tenBS.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Tên bác sĩ" }));

        datLich.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        datLich.setText("Đặt lịch khám");
        datLich.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                datLichActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(31, 31, 31)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(maBNTF, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tenBNTF, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(ngayKhamTF, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(yeuCauTF, javax.swing.GroupLayout.PREFERRED_SIZE, 250, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tenBS, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(136, 136, 136)
                        .addComponent(datLich, javax.swing.GroupLayout.PREFERRED_SIZE, 150, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(28, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(32, 32, 32)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(maBNTF, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(31, 31, 31)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(tenBNTF, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(30, 30, 30)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(ngayKhamTF, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(yeuCauTF, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tenBS, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(datLich, javax.swing.GroupLayout.PREFERRED_SIZE, 41, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(21, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void maBNTFFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_maBNTFFocusGained
        if (maBNTF.getText().equals("Mã bệnh nhân")) maBNTF.setText("");
    }//GEN-LAST:event_maBNTFFocusGained

    private void maBNTFFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_maBNTFFocusLost
        if (maBNTF.getText().equals("")) maBNTF.setText("Mã bệnh nhân");
    }//GEN-LAST:event_maBNTFFocusLost

    private void ngayKhamTFFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_ngayKhamTFFocusGained
        if (ngayKhamTF.getText().equals("dd-mm-yyyy")) ngayKhamTF.setText("");
    }//GEN-LAST:event_ngayKhamTFFocusGained

    private void ngayKhamTFFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_ngayKhamTFFocusLost
        if (ngayKhamTF.getText().equals("")) ngayKhamTF.setText("dd-mm-yyyy");
    }//GEN-LAST:event_ngayKhamTFFocusLost

    private void yeuCauTFFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_yeuCauTFFocusGained
        if (yeuCauTF.getText().equals("Yêu cầu khám")) yeuCauTF.setText("");
    }//GEN-LAST:event_yeuCauTFFocusGained

    private void yeuCauTFFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_yeuCauTFFocusLost
        if (yeuCauTF.getText().equals("")) yeuCauTF.setText("Yêu cầu khám");
    }//GEN-LAST:event_yeuCauTFFocusLost

    private void maBNTFActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_maBNTFActionPerformed
        try
        {
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl","c##java_lab5","123456");
            Statement sql = con.createStatement();
            ResultSet result = sql.executeQuery("SELECT TENBN FROM BENHNHAN WHERE MABN = '" + maBNTF.getText() + "'");
            if (result.next())
            {
                String name = result.getString("TENBN");
                tenBNTF.setText(name);
            }
            else
            {
                JOptionPane.showMessageDialog(this, "Bệnh nhân chưa đăng ký");
            }
            con.close();
        }
        catch (Exception e)
        {
            e.getMessage();
        }
    }//GEN-LAST:event_maBNTFActionPerformed

    private void datLichActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_datLichActionPerformed
        if (maBNTF.getText().equals("Mã bệnh nhân") || ngayKhamTF.getText().equals("dd-mm-yyyy")
                || yeuCauTF.getText().equals("Yêu cầu khám") || tenBS.getSelectedItem().equals("Tên bác sĩ"))
        {
            JOptionPane.showMessageDialog(this, "Đặt lịch không thành công");
        }
        else
        { 
            String maBS = "";
            int maKB = 0;
            try
            {
                Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl","c##java_lab5","123456");
                Statement maKBStm = con.createStatement();
                ResultSet maKBRS = maKBStm.executeQuery("SELECT MAX(MAKB) FROM KHAMBENH");
                if (maKBRS.next())
                {
                    String maxKB = maKBRS.getString("MAX(MAKB)");
                    String []afterSplit = maxKB.split("KB", 2);
                    maKB = Integer.parseInt(afterSplit[1].stripTrailing());
                }
                Statement maBSStm = con.createStatement();
                ResultSet maBSRS = maBSStm.executeQuery("SELECT MABS FROM BACSI WHERE TENBS = '" + tenBS.getSelectedItem() + "'");
                if (maBSRS.next())
                {
                    maBS = maBSRS.getString("MABS");
                }
                Statement alter = con.createStatement();
                alter.executeUpdate("ALTER SESSION SET NLS_DATE_FORMAT = 'dd-MM-yyyy HH24:MI:SS'");
                Statement insert = con.createStatement();
                insert.executeUpdate("INSERT INTO KHAMBENH(MAKB, MABN, MABS, NGAYKHAM, YEUCAUKHAM) VALUES ('KB" + Integer.toString(maKB+1) + "','" + maBNTF.getText() + "', '" + maBS + "', '" + ngayKhamTF.getText() + "', '" + yeuCauTF.getText() + "')");
                JOptionPane.showMessageDialog(this, "Đặt lịch thành công");
                maBNTF.setText("Mã bệnh nhân");
                tenBNTF.setText("Tên bệnh nhân");
                ngayKhamTF.setText("dd-mm-yyyy");
                yeuCauTF.setText("Yêu cầu khám");
                con.close();
            }
            catch (Exception e)
            {
                e.getMessage();
            }
        }
    }//GEN-LAST:event_datLichActionPerformed

    private void ngayKhamTFActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ngayKhamTFActionPerformed
        try
        {
            LocalDateTime dateNow = LocalDateTime.now();
            String formatedDate = dateNow.format(DateTimeFormatter.ofPattern("dd-mm-yyyy"));
            SimpleDateFormat format = new SimpleDateFormat("dd-mm-yyyy");
            Date today = format.parse(formatedDate);
            Date ngayKham = format.parse(ngayKhamTF.getText());
            if (!today.before(ngayKham))
            {
                JOptionPane.showMessageDialog(this, "Ngày không hợp lệ");
            }
        }
        catch (Exception e)
        {
            e.getMessage();
        }
    }//GEN-LAST:event_ngayKhamTFActionPerformed

    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(datLichKham.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(datLichKham.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(datLichKham.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(datLichKham.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new datLichKham().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton datLich;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JTextField maBNTF;
    private javax.swing.JTextField ngayKhamTF;
    private javax.swing.JTextField tenBNTF;
    private javax.swing.JComboBox<String> tenBS;
    private javax.swing.JTextField yeuCauTF;
    // End of variables declaration//GEN-END:variables
}
