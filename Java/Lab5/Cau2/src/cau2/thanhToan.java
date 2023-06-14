package cau2;

import java.awt.*;
import java.sql.*;
import java.text.SimpleDateFormat;
import java.text.DateFormat;
import java.text.ParseException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Locale;

import javax.swing.*;
import javax.swing.table.*;

/**
 *
 * @author nosc
 */

public class thanhToan extends javax.swing.JFrame {
    public thanhToan() {
        this.setVisible((true));
        this.setLocationRelativeTo(null);
        initComponents();
        JSpinner.DateEditor dateEditor = new JSpinner.DateEditor(dateSpinner, "dd-MM-yyyy");
        dateSpinner.setEditor(dateEditor);
    }

    String mabn, makb, tenbn, ketluan, yckham;
    Date ngaykham;
    boolean checkThanhToan;
    double tongtien;
    ArrayList<DichVu> listDV = new ArrayList<DichVu>();
    boolean isFirstTime = true;

    class BacSi {
        public String maBS;
        public String tenBS;

        public BacSi(String maBS, String tenBS) {
            this.maBS = maBS;
            this.tenBS = tenBS;
        }
    }

    class BenhNhan {
        public String maBN;
        public String tenBN;
        public Date ngSinh;
        public String dChi;
        public String dThoai;
        public int gioiTinh;

        public BenhNhan(String maBN, String tenBN, Date ngSinh, String dChi, String dThoai, int gioiTinh) {
            this.maBN = maBN;
            this.tenBN = tenBN;
            this.ngSinh = ngSinh;
            this.dChi = dChi;
            this.dThoai = dThoai;
            this.gioiTinh = gioiTinh;
        }
    }

    class KhamBenh {
        public String maKB;
        public String maBN;
        public String maBS;
        public Date ngayKham;
        public String yeuCauKham;
        public String ketLuan;
        public int thanhToan;

        public KhamBenh(String maKB, String maBN, String maBS, Date ngayKham, String yeuCauKham, String ketLuan,
                int thanhToan) {
            this.maKB = maKB;
            this.maBN = maBN;
            this.maBS = maBS;
            this.ngayKham = ngayKham;
            this.yeuCauKham = yeuCauKham;
            this.ketLuan = ketLuan;
            this.thanhToan = thanhToan;
        }
    }

    class DichVu {
        public String madv;
        public String tendv;
        public long dongia;
        public int soluong;
        public long thanhtien;

        public DichVu() {
        }

        public DichVu(String madv, String tendv, long dongia, int soluong) {
            this.madv = madv;
            this.tendv = tendv;
            this.dongia = dongia;
            this.soluong = soluong;
            this.thanhtien = this.dongia * this.soluong;
        }
    }

    class ThuPhi {
        public String maKB;
        public String maDV;
        public int soLuong;
        public double thanhTien;

        public ThuPhi(String maKB, String maDV, int soLuong, double thanhTien) {
            this.maKB = maKB;
            this.maDV = maDV;
            this.soLuong = soLuong;
            this.thanhTien = thanhTien;
        }
    }

    public static String getFormattedDate(JSpinner spinner) {
        Date selectedDate = (Date) spinner.getValue();
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");
        return dateFormat.format(selectedDate);
    }

    public static String convertDateFormat(String inputDate) {
        String[] monthNames = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        String[] parts = inputDate.split("-");
        int day = Integer.parseInt(parts[0]);
        int month = Integer.parseInt(parts[1]);
        int year = Integer.parseInt(parts[2]);

        String monthName = monthNames[month - 1];

        String result = String.format("%02d-%s-%04d", day, monthName, year);

        return result;
    }

    public static boolean isDateFormatValid(JSpinner spinner) {
        JSpinner.DateEditor dateEditor = (JSpinner.DateEditor) spinner.getEditor();
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");

        java.sql.Date selectedDate = new java.sql.Date(((java.util.Date) spinner.getValue()).getTime());
        String formattedDate = dateFormat.format(selectedDate);
        String editorFormat = dateEditor.getFormat().format(selectedDate);

        return formattedDate.equals(editorFormat);
    }

    public boolean GetInfoFromMaBN(String mabn, String ngkham) {
        boolean result = false;
        try {
            Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "c##java_lab5", "123456");
            Statement stmt = conn.createStatement();
            String sql = "SELECT * FROM KHAMBENH WHERE MABN = '" + mabn + "' AND NGAYKHAM = '" + ngkham + "'";
            ResultSet rs = stmt.executeQuery(sql);
            if (rs.next()) {
                makb = rs.getString("MAKB");
                result = true;
                System.out.println("Tìm thấy thông tin khám bệnh của bệnh nhân này!");
                ketluan = rs.getString("KETLUAN");
                ketluanTxt.setText(ketluan);

                yckham = rs.getString("YEUCAUKHAM");
                yeucaukhamTxt.setText(yckham);

                // ngaykham = rs.getDate("NGAYKHAM");
                // JSpinner.DateEditor dateEditor = new JSpinner.DateEditor(dateSpinner,
                // "dd-MM-yyyy");
                // dateSpinner.setEditor(dateEditor);
                // dateSpinner.setValue(ngaykham);

                checkThanhToan = (rs.getInt("THANHTOAN") == 1);

                if (checkThanhToan == true) {
                    payCheck.setSelected(true);
                    payCheck.setEnabled(false);
                    payBtn.setEnabled(false);
                } else {
                    payCheck.setSelected(false);
                    payCheck.setEnabled(true);
                    payBtn.setEnabled(true);
                }
            } else {
                JOptionPane.showMessageDialog(null, "Không tìm thấy thông tin khám bệnh của bệnh nhân này!");
            }
            conn.close();
            stmt.close();
            rs.close();
        } catch (Exception e) {
            // TODO: handle exception
            e.printStackTrace();
        }
        return result;
    }

    public String GetMaKB(String mabn) {
        String makb = "";
        try {
            Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "c##java_lab5", "123456");
            Statement stmt = conn.createStatement();
            String sql = "SELECT * FROM KHAMBENH WHERE MABN = '" + mabn + "'";
            ResultSet rs = stmt.executeQuery(sql);
            if (rs.next()) {
                makb = rs.getString("MAKB");
            }
            conn.close();
            stmt.close();
            rs.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return makb;
    }

    public int getSoLuong(String madv, String makb) {
        int soLuong = 0;
        try {
            Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "c##java_lab5", "123456");
            Statement stmt = conn.createStatement();
            String sql = "SELECT * FROM THUPHI WHERE MADV = '" + madv + "' AND MAKB = '" + makb + "'";
            ResultSet rs = stmt.executeQuery(sql);
            if (rs.next()) {
                soLuong = rs.getInt("SOLUONG");
            }
            conn.close();
            stmt.close();
            rs.close();
        } catch (Exception e) {
            // TODO: handle exception
        }
        return soLuong;
    }

    public DichVu GetDichVu(String madv, String makb) {
        DichVu dichvu = null;
        try {
            Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "c##java_lab5", "123456");
            Statement stmt = conn.createStatement();
            String sql = "SELECT * FROM DICHVU WHERE MADV = '" + madv + "'";
            ResultSet rs = stmt.executeQuery(sql);
            if (rs.next()) {
                String tendv = rs.getString("TENDV");
                long dongia = rs.getLong("DONGIA");
                int soluong = getSoLuong(madv, makb);
                dichvu = new DichVu(madv, tendv, dongia, soluong);
            }
            conn.close();
            stmt.close();
            rs.close();
        } catch (Exception e) {
            // TODO: handle exception
        }
        return dichvu;
    }

    public ArrayList<DichVu> GetListDV(String makb) {
        ArrayList<DichVu> dv = new ArrayList<DichVu>();
        try {
            Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "c##java_lab5", "123456");
            Statement stmt = conn.createStatement();
            String sql = "SELECT * FROM THUPHI WHERE MAKB = '" + makb + "'";
            ResultSet rs = stmt.executeQuery(sql);
            while (rs.next()) {
                String madv = rs.getString("MADV");
                DichVu temp = GetDichVu(madv, makb);
                dv.add(temp);
                System.out.println(temp.tendv);
            }
            conn.close();
            stmt.close();
            rs.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return dv;
    }

    public void SetDataDVTable(ArrayList<DichVu> dv) {
        String[] columnNames = { "Tên dịch vụ", "Số lượng", "Thành tiền" };
        Object[][] tableData = new Object[dv.size()][3];
        for (int i = 0; i < dv.size(); i++) {
            tableData[i][0] = dv.get(i).tendv;
            tableData[i][1] = dv.get(i).soluong;
            tableData[i][2] = dv.get(i).dongia;
        }
        DefaultTableModel model = new DefaultTableModel(tableData, columnNames);
        dichvuTable.setModel(model);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jToggleButton1 = new javax.swing.JToggleButton();
        jLabel1 = new javax.swing.JLabel();
        mabnTxt = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        tenbnTxt = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        ketluanTxt = new javax.swing.JTextField();
        jLabel5 = new javax.swing.JLabel();
        dateSpinner = new javax.swing.JSpinner();
        jLabel6 = new javax.swing.JLabel();
        yeucaukhamTxt = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        tongtienTxt = new javax.swing.JTextField();
        jLabel7 = new javax.swing.JLabel();
        payCheck = new javax.swing.JCheckBox();
        jScrollPane1 = new javax.swing.JScrollPane();
        dichvuTable = new javax.swing.JTable();
        payBtn = new javax.swing.JButton();

        jToggleButton1.setText("jToggleButton1");

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        jLabel1.setText("Mã bệnh nhân");

        mabnTxt.setFont(new java.awt.Font("Times New Roman", 1, 12)); // NOI18N
        mabnTxt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mabnTxtActionPerformed(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        jLabel2.setText("Tên bệnh nhân");

        tenbnTxt.setFont(new java.awt.Font("Times New Roman", 1, 12)); // NOI18N
        tenbnTxt.setEnabled(false);

        jLabel3.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        jLabel3.setText("Kết luận");

        ketluanTxt.setFont(new java.awt.Font("Times New Roman", 1, 12)); // NOI18N
        ketluanTxt.setEnabled(false);

        jLabel5.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        jLabel5.setText("Ngày khám");

        dateSpinner.setFont(new java.awt.Font("Times New Roman", 1, 12)); // NOI18N
        dateSpinner.setModel(new javax.swing.SpinnerDateModel());
        dateSpinner.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                dateSpinnerStateChanged(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        jLabel6.setText("Yêu cầu khám");

        yeucaukhamTxt.setFont(new java.awt.Font("Times New Roman", 1, 12)); // NOI18N
        yeucaukhamTxt.setEnabled(false);

        jLabel4.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        jLabel4.setText("Tổng tiền");

        tongtienTxt.setFont(new java.awt.Font("Times New Roman", 1, 12)); // NOI18N
        tongtienTxt.setEnabled(false);

        jLabel7.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        jLabel7.setText("Dịch vụ đã khám");

        payCheck.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        payCheck.setText("Thanh toán");

        dichvuTable.setFont(new java.awt.Font("Times New Roman", 0, 14)); // NOI18N
        dichvuTable.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Tên dịch vụ", "Số lượng", "Thành tiền"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.Object.class, java.lang.Object.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(dichvuTable);

        payBtn.setFont(new java.awt.Font("Times New Roman", 1, 14)); // NOI18N
        payBtn.setText("Thanh toán");
        payBtn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                payBtnActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(263, 263, 263)
                        .addComponent(payBtn))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(24, 24, 24)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 396, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(layout.createSequentialGroup()
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                            .addComponent(jLabel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(jLabel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                        .addGap(18, 18, 18)
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addComponent(mabnTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(tenbnTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE)
                                            .addComponent(ketluanTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE))
                                        .addGap(67, 67, 67)
                                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                            .addComponent(jLabel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(jLabel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                            .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 78, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                    .addComponent(jLabel7))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(yeucaukhamTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(tongtienTxt, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(dateSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, 168, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(payCheck))))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel5)
                            .addComponent(dateSpinner, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel6)
                            .addComponent(yeucaukhamTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel4)
                            .addComponent(tongtienTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel1)
                            .addComponent(mabnTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel2)
                            .addComponent(tenbnTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(18, 18, 18)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel3)
                            .addComponent(ketluanTxt, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(payCheck))
                .addGap(18, 18, 18)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 89, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(payBtn, javax.swing.GroupLayout.DEFAULT_SIZE, 32, Short.MAX_VALUE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void mabnTxtActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_mabnTxtActionPerformed
        // TODO add your handling code here:
        mabn = mabnTxt.getText();

    }// GEN-LAST:event_mabnTxtActionPerformed

    private void dateSpinnerStateChanged(javax.swing.event.ChangeEvent evt) {// GEN-FIRST:event_dateSpinnerStateChanged
        // TODO add your handling code here:
        if (isFirstTime) {
            isFirstTime = false;
            return;
        }

        if (isDateFormatValid(dateSpinner)) {
            java.util.Date selectedDate = (java.util.Date) dateSpinner.getValue();
            String formattedDate = new SimpleDateFormat("dd-MM-yyyy").format(selectedDate);
            String ngkham = convertDateFormat(formattedDate);
            try {
                Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "c##java_lab5", "123456");
                Statement st = con.createStatement();
                ResultSet rs_bn = st.executeQuery("SELECT * FROM BENHNHAN WHERE MABN = '" + mabn + "'");

                if (rs_bn.next()) {
                    if (GetInfoFromMaBN(mabn, ngkham)) {
                        tenbn = rs_bn.getString("TENBN");
                        tenbnTxt.setText(tenbn);
                        String makb = GetMaKB(mabn);
                        listDV = GetListDV(makb);
                        SetDataDVTable(listDV);
                    }
                } else {
                    JOptionPane.showMessageDialog(null, "Không tìm thấy bệnh nhân này!");
                }
            } catch (Exception e) {
                JOptionPane.showMessageDialog(null, e.getMessage());
            }
        }
    }// GEN-LAST:event_dateSpinnerStateChanged

    private void payBtnActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_payBtnActionPerformed
        // TODO add your handling code here:
        try {
            Connection conn = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orcl", "c##java_lab5", "123456");
            String sql = "UPDATE KHAMBENH SET thanhtoan = 1 WHERE MAKB = ?";
            PreparedStatement stmt = conn.prepareStatement(sql);
            stmt.setString(1, makb);
            int rowsAffected = stmt.executeUpdate();

            if (rowsAffected > 0) {
                JOptionPane.showMessageDialog(null, "Cập nhật dữ liệu thành công!");
                payCheck.setSelected(true);
                payCheck.setEnabled(false);
                payBtn.setEnabled(false);
            } else {
                JOptionPane.showMessageDialog(null, "Không tìm thấy phiếu khám!");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }// GEN-LAST:event_payBtnActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        // <editor-fold defaultstate="collapsed" desc=" Look and feel setting code
        // (optional) ">
        /*
         * If Nimbus (introduced in Java SE 6) is not available, stay with the default
         * look and feel.
         * For details see
         * http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(thanhToan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(thanhToan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(thanhToan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(thanhToan.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        // </editor-fold>
        // </editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new thanhToan().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JSpinner dateSpinner;
    private javax.swing.JTable dichvuTable;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JToggleButton jToggleButton1;
    private javax.swing.JTextField ketluanTxt;
    private javax.swing.JTextField mabnTxt;
    private javax.swing.JButton payBtn;
    private javax.swing.JCheckBox payCheck;
    private javax.swing.JTextField tenbnTxt;
    private javax.swing.JTextField tongtienTxt;
    private javax.swing.JTextField yeucaukhamTxt;
    // End of variables declaration//GEN-END:variables
}
