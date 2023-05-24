/**
 *
 * @author ThanhLinh
 */
public class toolBar extends javax.swing.JFrame {
    public toolBar() {
        initComponents();
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jToolBar2 = new javax.swing.JToolBar();
        openFolder = new javax.swing.JButton();
        save = new javax.swing.JButton();
        saveAs = new javax.swing.JButton();
        jSeparator1 = new javax.swing.JToolBar.Separator();
        printer = new javax.swing.JButton();
        weather = new javax.swing.JButton();
        facebook = new javax.swing.JButton();
        jSeparator2 = new javax.swing.JToolBar.Separator();
        desktop = new javax.swing.JButton();
        hand = new javax.swing.JButton();
        text = new javax.swing.JButton();
        cursor = new javax.swing.JButton();
        file = new javax.swing.JButton();
        camera = new javax.swing.JButton();
        lock = new javax.swing.JButton();
        pen = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Basic");
        setBackground(new java.awt.Color(0, 0, 0));
        setForeground(new java.awt.Color(0, 153, 153));
        setResizable(false);

        jToolBar2.setRollover(true);

        openFolder.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/open-folder.png"))); // NOI18N
        openFolder.setFocusable(false);
        openFolder.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        openFolder.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        openFolder.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                openFolderActionPerformed(evt);
            }
        });
        jToolBar2.add(openFolder);

        save.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/save.png"))); // NOI18N
        save.setFocusable(false);
        save.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        save.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        save.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveActionPerformed(evt);
            }
        });
        jToolBar2.add(save);

        saveAs.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/save-as.png"))); // NOI18N
        saveAs.setFocusable(false);
        saveAs.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        saveAs.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        saveAs.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                saveAsActionPerformed(evt);
            }
        });
        jToolBar2.add(saveAs);

        jSeparator1.setBackground(new java.awt.Color(0, 0, 0));
        jToolBar2.add(jSeparator1);

        printer.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/printer.png"))); // NOI18N
        printer.setFocusable(false);
        printer.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        printer.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        printer.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                printerActionPerformed(evt);
            }
        });
        jToolBar2.add(printer);

        weather.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/weather-forecast.png"))); // NOI18N
        weather.setFocusable(false);
        weather.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        weather.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        weather.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                weatherActionPerformed(evt);
            }
        });
        jToolBar2.add(weather);

        facebook.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/facebook.png"))); // NOI18N
        facebook.setFocusable(false);
        facebook.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        facebook.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        facebook.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                facebookActionPerformed(evt);
            }
        });
        jToolBar2.add(facebook);

        jSeparator2.setBackground(new java.awt.Color(0, 0, 0));
        jToolBar2.add(jSeparator2);

        desktop.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/desktop.png"))); // NOI18N
        desktop.setFocusable(false);
        desktop.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        desktop.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        desktop.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                desktopActionPerformed(evt);
            }
        });
        jToolBar2.add(desktop);

        hand.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/palm-of-hand.png"))); // NOI18N
        hand.setFocusable(false);
        hand.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        hand.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        hand.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                handActionPerformed(evt);
            }
        });
        jToolBar2.add(hand);

        text.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/text-format.png"))); // NOI18N
        text.setFocusable(false);
        text.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        text.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        text.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textActionPerformed(evt);
            }
        });
        jToolBar2.add(text);

        cursor.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/cursor.png"))); // NOI18N
        cursor.setFocusable(false);
        cursor.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        cursor.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        cursor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cursorActionPerformed(evt);
            }
        });
        jToolBar2.add(cursor);

        file.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/files.png"))); // NOI18N
        file.setFocusable(false);
        file.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        file.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        file.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                fileActionPerformed(evt);
            }
        });
        jToolBar2.add(file);

        camera.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/photo-camera-interface-symbol-for-button.png"))); // NOI18N
        camera.setFocusable(false);
        camera.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        camera.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        camera.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cameraActionPerformed(evt);
            }
        });
        jToolBar2.add(camera);

        lock.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/lock.png"))); // NOI18N
        lock.setFocusable(false);
        lock.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        lock.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        lock.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                lockActionPerformed(evt);
            }
        });
        jToolBar2.add(lock);

        pen.setIcon(new javax.swing.ImageIcon(getClass().getResource("/iconImage/pen.png"))); // NOI18N
        pen.setFocusable(false);
        pen.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        pen.setVerticalTextPosition(javax.swing.SwingConstants.BOTTOM);
        pen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                penActionPerformed(evt);
            }
        });
        jToolBar2.add(pen);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(0, 0, 0)
                .addComponent(jToolBar2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jToolBar2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void openFolderActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_openFolderActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Open Folder icon");
    }//GEN-LAST:event_openFolderActionPerformed

    private void saveActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Save icon");
    }//GEN-LAST:event_saveActionPerformed

    private void saveAsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_saveAsActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Save As icon");
    }//GEN-LAST:event_saveAsActionPerformed

    private void printerActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_printerActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Printer icon");
    }//GEN-LAST:event_printerActionPerformed

    private void weatherActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_weatherActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Weather icon");
    }//GEN-LAST:event_weatherActionPerformed

    private void facebookActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_facebookActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Facebook icon");
    }//GEN-LAST:event_facebookActionPerformed

    private void desktopActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_desktopActionPerformed
       javax.swing.JOptionPane.showMessageDialog(this, "You clicked Desktop icon");
    }//GEN-LAST:event_desktopActionPerformed

    private void handActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_handActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Hand icon");
    }//GEN-LAST:event_handActionPerformed

    private void textActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Text icon");
    }//GEN-LAST:event_textActionPerformed

    private void cursorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cursorActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Cursor icon");
    }//GEN-LAST:event_cursorActionPerformed

    private void fileActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_fileActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked File icon");
    }//GEN-LAST:event_fileActionPerformed

    private void cameraActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cameraActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Camera icon");
    }//GEN-LAST:event_cameraActionPerformed

    private void lockActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_lockActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Lock icon");
    }//GEN-LAST:event_lockActionPerformed

    private void penActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_penActionPerformed
        javax.swing.JOptionPane.showMessageDialog(this, "You clicked Pen icon");
    }//GEN-LAST:event_penActionPerformed
    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(toolBar.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(toolBar.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(toolBar.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(toolBar.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new toolBar().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton camera;
    private javax.swing.JButton cursor;
    private javax.swing.JButton desktop;
    private javax.swing.JButton facebook;
    private javax.swing.JButton file;
    private javax.swing.JButton hand;
    private javax.swing.JToolBar.Separator jSeparator1;
    private javax.swing.JToolBar.Separator jSeparator2;
    private javax.swing.JToolBar jToolBar2;
    private javax.swing.JButton lock;
    private javax.swing.JButton openFolder;
    private javax.swing.JButton pen;
    private javax.swing.JButton printer;
    private javax.swing.JButton save;
    private javax.swing.JButton saveAs;
    private javax.swing.JButton text;
    private javax.swing.JButton weather;
    // End of variables declaration//GEN-END:variables
}
