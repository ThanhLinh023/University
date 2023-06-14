package cau2;
import javax.swing.*;
import java.sql.*;

public class ttBenhNhan extends javax.swing.JFrame {
    public ttBenhNhan() {
        initComponents();
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        maBNTF = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        tenBNTF = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        ngSinhTF = new javax.swing.JTextField();
        diaChiTF = new javax.swing.JTextField();
        sdtTF = new javax.swing.JTextField();
        themBT = new javax.swing.JButton();
        gioiTinh = new javax.swing.JComboBox<>();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Thông tin bệnh nhân");

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

        jLabel2.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel2.setText("Tên bệnh nhân");

        tenBNTF.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tenBNTF.setText("Tên bệnh nhân");
        tenBNTF.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                tenBNTFFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                tenBNTFFocusLost(evt);
            }
        });

        jLabel3.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel3.setText("Ngày sinh");

        jLabel4.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel4.setText("Địa chỉ");

        jLabel5.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel5.setText("Điện thoại");

        jLabel6.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        jLabel6.setText("Giới tính");

        ngSinhTF.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        ngSinhTF.setText("dd-mm-yyyy");
        ngSinhTF.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                ngSinhTFFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                ngSinhTFFocusLost(evt);
            }
        });

        diaChiTF.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        diaChiTF.setText("Địa chỉ");
        diaChiTF.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                diaChiTFFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                diaChiTFFocusLost(evt);
            }
        });

        sdtTF.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        sdtTF.setText("Số điện thoại");
        sdtTF.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                sdtTFFocusGained(evt);
            }
            public void focusLost(java.awt.event.FocusEvent evt) {
                sdtTFFocusLost(evt);
            }
        });

        themBT.setFont(new java.awt.Font("Segoe UI", 1, 14)); // NOI18N
        themBT.setText("Thêm");
        themBT.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                themBTActionPerformed(evt);
            }
        });

        gioiTinh.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        gioiTinh.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Nam", "Nu" }));

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(30, 30, 30)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 125, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(maBNTF, javax.swing.GroupLayout.DEFAULT_SIZE, 240, Short.MAX_VALUE)
                            .addComponent(tenBNTF, javax.swing.GroupLayout.DEFAULT_SIZE, 240, Short.MAX_VALUE)
                            .addComponent(ngSinhTF)
                            .addComponent(diaChiTF)
                            .addComponent(sdtTF)
                            .addComponent(gioiTinh, javax.swing.GroupLayout.PREFERRED_SIZE, 164, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(137, 137, 137)
                        .addComponent(themBT, javax.swing.GroupLayout.PREFERRED_SIZE, 173, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(29, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(maBNTF, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(tenBNTF, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(ngSinhTF, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(diaChiTF, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(29, 29, 29)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(sdtTF, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 34, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(gioiTinh, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(30, 30, 30)
                .addComponent(themBT, javax.swing.GroupLayout.PREFERRED_SIZE, 45, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(15, 15, 15))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void maBNTFFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_maBNTFFocusGained
        if (maBNTF.getText().equals("Mã bệnh nhân")) maBNTF.setText("");
    }//GEN-LAST:event_maBNTFFocusGained

    private void maBNTFFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_maBNTFFocusLost
        if (maBNTF.getText().equals("")) maBNTF.setText("Mã bệnh nhân");
    }//GEN-LAST:event_maBNTFFocusLost

    private void tenBNTFFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_tenBNTFFocusGained
        if (tenBNTF.getText().equals("Tên bệnh nhân")) tenBNTF.setText("");
    }//GEN-LAST:event_tenBNTFFocusGained

    private void tenBNTFFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_tenBNTFFocusLost
        if (tenBNTF.getText().equals("")) tenBNTF.setText("Tên bệnh nhân");
    }//GEN-LAST:event_tenBNTFFocusLost

    private void ngSinhTFFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_ngSinhTFFocusGained
        if (ngSinhTF.getText().equals("dd-mm-yyyy")) ngSinhTF.setText("");
    }//GEN-LAST:event_ngSinhTFFocusGained

    private void ngSinhTFFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_ngSinhTFFocusLost
        if (ngSinhTF.getText().equals("")) ngSinhTF.setText("dd-mm-yyyy");
    }//GEN-LAST:event_ngSinhTFFocusLost

    private void diaChiTFFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_diaChiTFFocusGained
        if (diaChiTF.getText().equals("Địa chỉ")) diaChiTF.setText("");
    }//GEN-LAST:event_diaChiTFFocusGained

    private void diaChiTFFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_diaChiTFFocusLost
        if (diaChiTF.getText().equals("")) diaChiTF.setText("Địa chỉ");
    }//GEN-LAST:event_diaChiTFFocusLost

    private void sdtTFFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_sdtTFFocusGained
        if (sdtTF.getText().equals("Số điện thoại")) sdtTF.setText("");
    }//GEN-LAST:event_sdtTFFocusGained

    private void sdtTFFocusLost(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_sdtTFFocusLost
        if (sdtTF.getText().equals("")) sdtTF.setText("Số điện thoại");
    }//GEN-LAST:event_sdtTFFocusLost

    private void themBTActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_themBTActionPerformed
        if (maBNTF.getText().equals("Mã bệnh nhân") || tenBNTF.equals("Tên bệnh nhân") || ngSinhTF.getText().equals("dd-mm-yyyy")
                || diaChiTF.getText().equals("Địa chỉ") || sdtTF.getText().equals("Số điện thoại"))
        {
            JOptionPane.showMessageDialog(this, "Thêm không thành công");
        }
        else
        {
            try
            {
                Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl","c##java_lab5","123456");
                Statement alterSession = con.createStatement();
                alterSession.executeUpdate("ALTER SESSION SET NLS_DATE_FORMAT = 'dd-MM-yyyy HH24:MI:SS'");
                Statement insert = con.createStatement();
                String sql = "INSERT INTO BENHNHAN(MABN) VALUES ('" + maBNTF.getText() + "')";
                insert.executeUpdate(sql);
                insert.execute("UPDATE BENHNHAN SET TENBN = '" + tenBNTF.getText() + "' WHERE MABN = '" + maBNTF.getText() + "'");
                insert.execute("UPDATE BENHNHAN SET NGSINH = '" + ngSinhTF.getText() + "' WHERE MABN = '" + maBNTF.getText() + "'");
                insert.execute("UPDATE BENHNHAN SET DCHI = '" + diaChiTF.getText() + "' WHERE MABN = '" + maBNTF.getText() + "'");
                insert.execute("UPDATE BENHNHAN SET DTHOAI = '" + sdtTF.getText() + "' WHERE MABN = '" + maBNTF.getText() + "'");
                insert.execute("UPDATE BENHNHAN SET GIOITINH = '" + gioiTinh.getSelectedItem() + "' WHERE MABN = '" + maBNTF.getText() + "'");
                JOptionPane.showMessageDialog(this, "Thêm thành công");
                maBNTF.setText("Mã bệnh nhân");
                tenBNTF.setText("Tên bệnh nhân");
                ngSinhTF.setText("dd-mm-yyyy");
                diaChiTF.setText("Địa chỉ");
                sdtTF.setText("Số điện thoại");
                con.close();
            }
            catch(Exception e)
            {
                JOptionPane.showMessageDialog(this, e.getMessage());
            }
        }
    }//GEN-LAST:event_themBTActionPerformed

    public static void main(String args[]) {
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
            java.util.logging.Logger.getLogger(ttBenhNhan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ttBenhNhan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ttBenhNhan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ttBenhNhan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ttBenhNhan().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField diaChiTF;
    private javax.swing.JComboBox<String> gioiTinh;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JTextField maBNTF;
    private javax.swing.JTextField ngSinhTF;
    private javax.swing.JTextField sdtTF;
    private javax.swing.JTextField tenBNTF;
    private javax.swing.JButton themBT;
    // End of variables declaration//GEN-END:variables
}
