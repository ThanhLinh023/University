package cau2.Controller;

import Model.BacSiModel;
import cau2.KhamBenh;
import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.ResultSet;
import java.util.ArrayList;
import oracle.jdbc.OracleTypes;
public class BacSiController {
    public ArrayList<BacSiModel> getTCBS(){
        ArrayList<BacSiModel> bsModel = new ArrayList<BacSiModel>();
        String sql  = "";
        Connection conn = null;
        ResultSet rs = null;
        CallableStatement callsql = null;
        
        try {
            conn = KhamBenh.getJDBCConnection();
            sql = "{call GETTCBS(?)}";
            callsql = conn.prepareCall(sql);
            callsql.registerOutParameter(1, OracleTypes.CURSOR);
            callsql.execute();
            rs = (ResultSet) callsql.getObject(1);
            
            while(rs.next()){
                BacSiModel bs = new BacSiModel(
                                       rs.getString("MABS"),
                                       rs.getString("TENBS"));
                bsModel.add(bs);
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        return bsModel;
    }
}
