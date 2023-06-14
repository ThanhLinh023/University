package cau2;
public class MainScreen extends javax.swing.JFrame {
    public MainScreen() {
        initComponents();
        this.setLocationRelativeTo(null);
        this.setVisible(true);
    }
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        TTBNBt = new javax.swing.JButton();
        datLichBt = new javax.swing.JButton();
        khamBenhBt = new javax.swing.JButton();
        thanhToanBt = new javax.swing.JButton();
        outBt = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Màn hình chính");

        jPanel1.setBackground(new java.awt.Color(204, 204, 204));
        jPanel1.setForeground(new java.awt.Color(255, 255, 255));

        TTBNBt.setFont(new java.awt.Font("Segoe UI", 1, 12)); // NOI18N
        TTBNBt.setText("Thông tin bệnh nhân");
        TTBNBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                TTBNBtActionPerformed(evt);
            }
        });

        datLichBt.setFont(new java.awt.Font("Segoe UI", 1, 12)); // NOI18N
        datLichBt.setText("Đặt lịch khám bệnh");
        datLichBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                datLichBtActionPerformed(evt);
            }
        });

        khamBenhBt.setFont(new java.awt.Font("Segoe UI", 1, 12)); // NOI18N
        khamBenhBt.setText("Khám bệnh");
        khamBenhBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                khamBenhBtActionPerformed(evt);
            }
        });

        thanhToanBt.setFont(new java.awt.Font("Segoe UI", 1, 12)); // NOI18N
        thanhToanBt.setText("Thanh toán");
        thanhToanBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                thanhToanBtActionPerformed(evt);
            }
        });

        outBt.setFont(new java.awt.Font("Segoe UI", 1, 12)); // NOI18N
        outBt.setText("Thoát");
        outBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                outBtActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(36, 36, 36)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(TTBNBt, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(khamBenhBt, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 42, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(datLichBt, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(thanhToanBt, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(37, 37, 37))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(135, 135, 135)
                .addComponent(outBt, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(43, 43, 43)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(TTBNBt, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(datLichBt, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(69, 69, 69)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(khamBenhBt, javax.swing.GroupLayout.DEFAULT_SIZE, 40, Short.MAX_VALUE)
                    .addComponent(thanhToanBt, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 50, Short.MAX_VALUE)
                .addComponent(outBt, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18))
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

    private void TTBNBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_TTBNBtActionPerformed
        this.dispose();
        new ttBenhNhan();
    }//GEN-LAST:event_TTBNBtActionPerformed

    private void datLichBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_datLichBtActionPerformed
        this.dispose();
        new datLichKham();
    }//GEN-LAST:event_datLichBtActionPerformed

    private void khamBenhBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_khamBenhBtActionPerformed
        this.dispose();
        new KhamBenh();
    }//GEN-LAST:event_khamBenhBtActionPerformed

    private void thanhToanBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_thanhToanBtActionPerformed
        this.dispose();
        new thanhToan();
    }//GEN-LAST:event_thanhToanBtActionPerformed

    private void outBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_outBtActionPerformed
        this.dispose();
    }//GEN-LAST:event_outBtActionPerformed
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MainScreen().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton TTBNBt;
    private javax.swing.JButton datLichBt;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JButton khamBenhBt;
    private javax.swing.JButton outBt;
    private javax.swing.JButton thanhToanBt;
    // End of variables declaration//GEN-END:variables
}
