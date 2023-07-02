package vietnamprovincesearching;
import vietnamprovincesearching.VPSModel;
import vietnamprovincesearching.VPSController;
import javax.swing.*;
import java.util.Map.Entry;
public class VPSView extends javax.swing.JFrame {
    VPSModel data;
    public VPSView() {
        initComponents();
        this.setVisible(true);
        this.setLocationRelativeTo(null);
        initialData();
    }
    public void initialData()
    {
        data = new VPSModel();
        for (String i : data.getCity().values())
        {
            city.addItem(i);
        }
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        city = new javax.swing.JComboBox<>();
        district = new javax.swing.JComboBox<>();
        searchBt = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Vietnam Province Searching");
        setResizable(false);

        city.setFont(new java.awt.Font("Dialog", 0, 14)); // NOI18N
        city.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Tỉnh/Thành phố" }));
        city.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cityActionPerformed(evt);
            }
        });

        district.setFont(new java.awt.Font("Dialog", 0, 14)); // NOI18N
        district.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Quận/Huyện" }));

        searchBt.setFont(new java.awt.Font("Dialog", 0, 14)); // NOI18N
        searchBt.setText("Tra cứu");
        searchBt.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                searchBtActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addComponent(city, javax.swing.GroupLayout.PREFERRED_SIZE, 183, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(62, 62, 62)
                .addComponent(district, javax.swing.GroupLayout.PREFERRED_SIZE, 160, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(30, Short.MAX_VALUE))
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(searchBt, javax.swing.GroupLayout.PREFERRED_SIZE, 148, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(147, 147, 147))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(67, 67, 67)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(city, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(district, javax.swing.GroupLayout.PREFERRED_SIZE, 40, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 47, Short.MAX_VALUE)
                .addComponent(searchBt, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(30, 30, 30))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void cityActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cityActionPerformed
        if (!city.getSelectedItem().equals("Tỉnh/Thành Phố"))
        {
            String currCity = city.getSelectedItem().toString();
            String cityCode = "";
            district.removeAllItems();
            district.addItem("Quận/Huyện");
            for (Entry<String, String> i : data.getCity().entrySet())
            {
                if (i.getValue().equals(currCity))
                {
                    cityCode = i.getKey();
                    break;
                }
            }
            for (String i : data.getDistrict().keySet())
            {
                if (i.startsWith(cityCode))
                {
                    district.addItem(data.getDistrict().get(i));
                }
            }
        }
    }//GEN-LAST:event_cityActionPerformed

    private void searchBtActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_searchBtActionPerformed
        if (city.getSelectedItem().equals("Tỉnh/Thành phố") || district.getSelectedItem().equals("Quận/Huyện"))
        {
            JOptionPane.showMessageDialog(this, "Không tìm thấy thông tin");
        }
        else
        {
            VPSController show = new VPSController();
            JOptionPane.showMessageDialog(this, show.showInformation(city.getSelectedItem().toString(), district.getSelectedItem().toString()));
        }
    }//GEN-LAST:event_searchBtActionPerformed

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(VPSView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VPSView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VPSView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VPSView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VPSView().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JComboBox<String> city;
    private javax.swing.JComboBox<String> district;
    private javax.swing.JButton searchBt;
    // End of variables declaration//GEN-END:variables
}
