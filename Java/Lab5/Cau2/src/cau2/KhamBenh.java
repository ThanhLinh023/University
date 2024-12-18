package cau2;

import cau2.Controller.BacSiController;
import cau2.Controller.DichVuController;
import cau2.Controller.KhamBenhController;
import Model.BacSiModel;
import Model.BenhNhanModel;
import Model.DichVuModel;
import Model.KhamBenhModel;
import Model.ThuPhiModel;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
public class KhamBenh extends javax.swing.JFrame {

    public KhamBenh() {
        initComponents();
        setLocationRelativeTo(null);
        GetTCDV();
        GetTCBS();
        GetTCBN();
        GetTCDVBS();
        jTextField1.setEditable(false);
    }
    
    DefaultTableModel table = new DefaultTableModel();
    DefaultTableModel table_bs = new DefaultTableModel();
    DichVuController dv = new DichVuController();
    BacSiController bs = new BacSiController();
    ArrayList<BacSiModel> bsModel = null;
    ArrayList<DichVuModel> dvModel = null;
    ArrayList<DichVuModel> dschon = new ArrayList<DichVuModel>();
    ArrayList<BenhNhanModel> bnModel = null;
    KhamBenhController bn = new KhamBenhController();
    KhamBenhModel kbModel = null;
    
    public static Connection getJDBCConnection(String hostName, String sid,
    String userName, String password) throws ClassNotFoundException, SQLException{
        Class.forName("oracle.jdbc.driver.OracleDriver");
        String connectionURL = "jdbc:oracle:thin:@" + hostName + ":1521:" + sid;

        Connection conn = DriverManager.getConnection(connectionURL, userName,
                password);
        return conn;
    }
    
    public static Connection getJDBCConnection() throws SQLException, ClassNotFoundException {
        String hostName = "localhost";
        String sid = "orcl";
        String userName = "c##java_lab5";
        String password = "123456";
        return getJDBCConnection(hostName, sid, userName, password);
    }
    
    public void GetTCDV(){
        String title[] = {"Tên dịch vụ"};
        table.setColumnIdentifiers(title);
        table.setRowCount(0);
        dvModel = dv.getTCDV();
        for(DichVuModel i : dvModel){
            Object[] obj = {i.getTenDV()};
            table.addRow(obj);
        }
        jTable1.setModel(table);
        jTable1.setRowHeight(30);
    }
    
    public void GetTCDVBS(){
        String title[] = {"Tên dịch vụ", "Số lượng"};
        table_bs.setColumnIdentifiers(title);
        table_bs.setRowCount(0);
        jTable2.setModel(table_bs);
        jTable2.setRowHeight(30);
    }
    
    public void GetTCBS(){
        jComboBox1.removeAllItems();
        bsModel = bs.getTCBS();
        for(BacSiModel i : bsModel){
            jComboBox1.addItem(i.getName());
        }
    }
    
    public void GetTCBN() {
    LocalDate date1 = datePicker1.getDate();
    jComboBox2.removeAllItems();
    if (jComboBox1.getSelectedIndex() == -1 || date1 == null) {
        return;
    } else {
        jComboBox2.removeAllItems();
        if (!bsModel.isEmpty()) {
            String MaBS = bsModel.get(jComboBox1.getSelectedIndex()).getId();
            String NKBBN = "";
            LocalDate NKB = null;
            if (date1 != null) {
                NKBBN = date1.format(DateTimeFormatter.ofPattern("dd-MM-yyyy"));
                NKB = LocalDate.parse(NKBBN, DateTimeFormatter.ofPattern("dd-MM-yyyy"));
            } else {
                 NKB = LocalDate.now();
            }
            bnModel = bn.getTCBN(MaBS, NKB);
            for (BenhNhanModel i : bnModel) {
                jComboBox2.addItem(i.getTenBN());
            }
        }
    }
}
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel2 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jComboBox1 = new javax.swing.JComboBox<>();
        jComboBox2 = new javax.swing.JComboBox<>();
        datePicker1 = new com.github.lgooddatepicker.components.DatePicker();
        jTextField1 = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        jTextField2 = new javax.swing.JTextField();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTable2 = new javax.swing.JTable();
        Them = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Khám bệnh");

        jPanel2.setBackground(new java.awt.Color(204, 204, 204));

        jLabel1.setText("Ngày khám");
        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(0, 0, 0));

        jLabel2.setText("Tên bệnh nhân");
        jLabel2.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel2.setForeground(new java.awt.Color(0, 0, 0));

        jLabel3.setText("Bác sĩ khám");
        jLabel3.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel3.setForeground(new java.awt.Color(0, 0, 0));

        jLabel4.setText("Yêu cầu khám");
        jLabel4.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel4.setForeground(new java.awt.Color(0, 0, 0));

        jComboBox1.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));
        jComboBox1.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jComboBox1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBox1ActionPerformed(evt);
            }
        });

        jComboBox2.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));
        jComboBox2.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jComboBox2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBox2ActionPerformed(evt);
            }
        });

        datePicker1.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        datePicker1.addPropertyChangeListener(new java.beans.PropertyChangeListener() {
            public void propertyChange(java.beans.PropertyChangeEvent evt) {
                datePicker1PropertyChange(evt);
            }
        });

        jTextField1.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N

        jLabel5.setText("Kết luận");
        jLabel5.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel5.setForeground(new java.awt.Color(0, 0, 0));

        jTextField2.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N

        jLabel6.setText("Danh sách dịch vụ");
        jLabel6.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel6.setForeground(new java.awt.Color(0, 0, 0));

        jLabel7.setText("Danh sách dịch vụ bác sĩ chọn");
        jLabel7.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel7.setForeground(new java.awt.Color(0, 0, 0));

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null},
                {null},
                {null},
                {null}
            },
            new String [] {
                "Tên dịch vụ"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }
        });
        jTable1.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jTable1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jTable1MouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(jTable1);

        jTable2.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null},
                {null, null},
                {null, null},
                {null, null}
            },
            new String [] {
                "Tên dịch vụ", "Số lượng"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.Integer.class
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }
        });
        jScrollPane2.setViewportView(jTable2);

        Them.setText("Thêm");
        Them.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        Them.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ThemActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel2)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jComboBox2, javax.swing.GroupLayout.PREFERRED_SIZE, 133, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel3)
                                .addGap(39, 39, 39)
                                .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, 133, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(18, 18, 18)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel4)
                            .addComponent(jLabel1))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jTextField1)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addComponent(datePicker1, javax.swing.GroupLayout.PREFERRED_SIZE, 252, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(0, 57, Short.MAX_VALUE)))
                        .addContainerGap())
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(jLabel5)
                        .addGap(73, 73, 73)
                        .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, 307, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createSequentialGroup()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel2Layout.createSequentialGroup()
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 278, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(javax.swing.GroupLayout.Alignment.LEADING, jPanel2Layout.createSequentialGroup()
                                .addComponent(jLabel6)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jLabel7)))
                        .addGap(28, 28, 28))))
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(297, 297, 297)
                .addComponent(Them, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel3, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(datePicker1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(34, 34, 34)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4)
                    .addComponent(jComboBox2, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(37, 37, 37)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jTextField2, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(44, 44, 44)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel7, javax.swing.GroupLayout.PREFERRED_SIZE, 35, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 189, Short.MAX_VALUE)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 35, Short.MAX_VALUE)
                .addComponent(Them, javax.swing.GroupLayout.PREFERRED_SIZE, 49, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(33, 33, 33))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void ThemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ThemActionPerformed
        // TODO add your handling code here:
        if(jTextField2.getText().equals("CHƯA CÓ")){
           JOptionPane.showMessageDialog(null, "Vui lòng thêm kết luận", "Lỗi", JOptionPane.ERROR_MESSAGE);
        } else {
            for(int i=0; i<table_bs.getRowCount(); i++){
                String MaKB = kbModel.getMaKB();
                String MaDV = dschon.get(i).getMaDV();
                int sl = Integer.parseInt(table_bs.getValueAt(i, 1).toString());
                long TongTien = dschon.get(i).getDongia() * sl;
                ThuPhiModel tp = new ThuPhiModel(MaKB, MaDV, sl, TongTien);
                int check = bn.InsertThuPhi(tp);
                System.out.println(check);
            }
            kbModel.setKetLuan(jTextField2.getText());
            int check = bn.update(kbModel);
            if(check != 0){
                JOptionPane.showMessageDialog(this, "Thêm dữ liệu thành công");
            }
            GetTCDV();
            GetTCDVBS();
            jTextField2.setText("");
        }
        
    }//GEN-LAST:event_ThemActionPerformed

    private void jTable1MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jTable1MouseClicked
        // TODO add your handling code here:
        jTable1.setDefaultEditor(Object.class, null);
        int selectedRow = jTable1.getSelectedRow();
        if(selectedRow >= 0 && selectedRow <= table.getRowCount()){
            dschon.add(dvModel.get(selectedRow));
            String obj[] = new String[4];
            obj[0] = table.getValueAt(selectedRow, 0).toString();
            obj[1] = "1";
            table_bs.addRow(obj);
            table.removeRow(selectedRow);
        }
    }//GEN-LAST:event_jTable1MouseClicked

    private void jComboBox1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBox1ActionPerformed
        // TODO add your handling code here:
        GetTCBN();
        kbModel = null;
    }//GEN-LAST:event_jComboBox1ActionPerformed

    private void datePicker1PropertyChange(java.beans.PropertyChangeEvent evt) {//GEN-FIRST:event_datePicker1PropertyChange
        // TODO add your handling code here:
        if(jComboBox1.getItemCount() > 0)
            GetTCBN();
    }//GEN-LAST:event_datePicker1PropertyChange

    private void jComboBox2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBox2ActionPerformed
        // TODO add your handling code here:
        jTextField1.setText("");
        if(jComboBox2.getSelectedIndex() >= 0){
            LocalDate date1 = datePicker1.getDate();
            String NKBBN = "";
            LocalDate NKB = null;
            if (date1 != null) {
                NKBBN = date1.format(DateTimeFormatter.ofPattern("dd-MM-yyyy"));
                NKB = LocalDate.parse(NKBBN, DateTimeFormatter.ofPattern("dd-MM-yyyy"));
            }
            String MaBS = bsModel.get(jComboBox1.getSelectedIndex()).getId();
            String MaBN = bnModel.get(jComboBox2.getSelectedIndex()).getMaBN();
            kbModel = bn.getBNYCKham(MaBS, MaBN, NKB);
            jTextField1.setText(kbModel.getYCKham());
            jTextField2.setText(kbModel.getKetLuan());
        }
    }//GEN-LAST:event_jComboBox2ActionPerformed

    
    
    /**
     * @param args the command line arguments
     */
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
            java.util.logging.Logger.getLogger(KhamBenh.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(KhamBenh.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(KhamBenh.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(KhamBenh.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new KhamBenh().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Them;
    private com.github.lgooddatepicker.components.DatePicker datePicker1;
    private javax.swing.JComboBox<String> jComboBox1;
    private javax.swing.JComboBox<String> jComboBox2;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable jTable1;
    private javax.swing.JTable jTable2;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JTextField jTextField2;
    // End of variables declaration//GEN-END:variables
}
