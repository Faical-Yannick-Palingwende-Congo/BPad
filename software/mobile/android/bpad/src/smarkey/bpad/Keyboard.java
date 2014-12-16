package smarkey.bpad;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;

public class Keyboard extends Activity implements OnClickListener {

	EditText binaryView;
	EditText asciiView;
	
	Button shift;
	Button one;
	
	char[] binary = new char[8];
	int position = 0;
	
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_keyboard);
		
		binaryView = (EditText) findViewById(R.id.binary_view);
		asciiView = (EditText) findViewById(R.id.ascii_view);
		
		shift = (Button) findViewById(R.id.key_shift);
		one = (Button) findViewById(R.id.key_1);
		
		shift.setOnClickListener(this);
		one.setOnClickListener(this);
		
		empty_binary();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.keyboard, menu);
		return true;
	}

	@Override
	public void onClick(View v) {
		if(v == shift){
			
			if(position >= 7){
				binary[position] = '0';
				String ascii = binary2Ascii(new String(binary));
				binaryView.setText(new String(binary));
				asciiView.setText(ascii);
				position = 0;
				empty_binary();
			}else {
				if(position == 0){
					asciiView.setText("");
				}
				binary[position] = '0';
				binaryView.setText(new String(binary));
				position++;
			}
		}else if(v == one){
			
			if(position >= 7){
				binary[position] = '1';
				String ascii = binary2Ascii(new String(binary));
				binaryView.setText(new String(binary));
				asciiView.setText(ascii);
				position = 0;
				empty_binary();
			}else {
				if(position == 0){
					asciiView.setText("");
				}
				binary[position] = '1';
				binaryView.setText(new String(binary));
				position++;
			}
		}
		
	}
	
	String binary2Ascii(String binary){
		int bin = Integer.parseInt(binary);
		switch(bin){
			case 0:
				return "NULL";
			case 1:
				return "SOH";
			case 10:
				return "STX";
			case 11:
				return "EXT";
			case 100:
				return "EOT";
			case 101:
				return "ENQ";
			case 110:
				return "ACK";
			case 111:
				return "BEL";
			case 1000:
				return "BS";
			case 1001:
				return "TAB";
			case 1010:
				return "LF";
			case 1011:
				return "VT";
			case 1100:
				return "FF";
			case 1101:
				return "CR";
			case 1110:
				return "SO";
			case 1111:
				return "SI";
			case 10000:
				return "DLE";
			case 10001:
				return "DC1";
			case 10010:
				return "DC2";
			case 10011:
				return "DC3";
			case 10100:
				return "DC4";
			case 10101:
				return "NAK";
			case 10110:
				return "SYN";
			case 10111:
				return "ETB";
			case 11000:
				return "CAN";
			case 11001:
				return "EM";
			case 11010:
				return "SUB";
			case 11011:
				return "ESC";
			case 11100:
				return "FS";
			case 11101:
				return "GS";
			case 11110:
				return "RS";
			case 11111:
				return "US";
			case 100000:
				return "SPACE";
			case 100001:
				return "!";
			case 100010:
				return "\"";
			case 100011:
				return "#";
			case 100100:
				return "$";
			case 100101:
				return "%";
			case 100110:
				return "&";
			case 100111:
				return "\'";
			case 101000:
				return "(";
			case 101001:
				return ")";
			case 101010:
				return "*";
			case 101011:
				return "+";
			case 101100:
				return ",";
			case 101101:
				return "-";
			case 101110:
				return ".";
			case 101111:
				return "/";
			case 110000:
				return "0";
			case 110001:
				return "1";
			case 110010:
				return "2";
			case 110011:
				return "3";
			case 110100:
				return "4";
			case 110101:
				return "5";
			case 110110:
				return "6";
			case 110111:
				return "7";
			case 111000:
				return "8";
			case 111001:
				return "9";
			case 111010:
				return ":";
			case 111011:
				return ";";
			case 111100:
				return "<";
			case 111101:
				return "=";
			case 111110:
				return ">";
			case 111111:
				return "?";
			case 1000000:
				return "@";
			case 1000001:
				return "A";
			case 1000010:
				return "B";
			case 1000011:
				return "C";
			case 1000100:
				return "D";
			case 1000101:
				return "E";
			case 1000110:
				return "F";
			case 1000111:
				return "G";
			case 1001000:
				return "H";
			case 1001001:
				return "I";
			case 1001010:
				return "J";
			case 1001011:
				return "K";
			case 1001100:
				return "L";
			case 1001101:
				return "M";
			case 1001110:
				return "N";
			case 1001111:
				return "O";
			case 1010000:
				return "P";
			case 1010001:
				return "Q";
			case 1010010:
				return "R";
			case 1010011:
				return "S";
			case 1010100:
				return "T";
			case 1010101:
				return "U";
			case 1010110:
				return "V";
			case 1010111:
				return "W";
			case 1011000:
				return "X";
			case 1011001:
				return "Y";
			case 1011010:
				return "Z";
			case 1011011:
				return "[";
			case 1011100:
				return "\\";
			case 1011101:
				return "]";
			case 1011110:
				return "ˆ";
			case 1011111:
				return "_";
			case 1100000:
				return "`";
			case 1100001:
				return "a";
			case 1100010:
				return "b";
			case 1100011:
				return "c";
			case 1100100:
				return "d";
			case 1100101:
				return "e";
			case 1100110:
				return "f";
			case 1100111:
				return "g'";
			case 1101000:
				return "h";
			case 1101001:
				return "i";
			case 1101010:
				return "j";
			case 1101011:
				return "k";
			case 1101100:
				return "l";
			case 1101101:
				return "m";
			case 1101110:
				return "n";
			case 1101111:
				return "o";
			case 1110000:
				return "p";
			case 1110001:
				return "q";
			case 1110010:
				return "r";
			case 1110011:
				return "s";
			case 1110100:
				return "t";
			case 1110101:
				return "u";
			case 1110110:
				return "v";
			case 1110111:
				return "w";
			case 1111000:
				return "x";
			case 1111001:
				return "y";
			case 1111010:
				return "z";
			case 1111011:
				return "{";
			case 1111100:
				return "|";
			case 1111101:
				return "}";
			case 1111110:
				return "~";
			case 1111111:
				return "DEL";
			case 10000000:
				return "Ç";
			case 10000001:
				return "û";
			case 10000010:
				return "é";
			case 10000011:
				return "â";
			case 10000100:
				return "ä";
			case 10000101:
				return "à";
			case 10000110:
				return "å";
			case 10000111:
				return "ç";
			case 10001000:
				return "ê";
			case 10001001:
				return "ë";
			case 10001010:
				return "è";
			case 10001011:
				return "ï";
			case 10001100:
				return "î";
			case 10001101:
				return "ì";
			case 10001110:
				return "Ä";
			case 10001111:
				return "Å";
			case 10010000:
				return "É";
			case 10010001:
				return "æ";
			case 10010010:
				return "Æ";
			case 10010011:
				return "ô";
			case 10010100:
				return "ö";
			case 10010101:
				return "ò";
			case 10010110:
				return "û";
			case 10010111:
				return "ù";
			case 10011000:
				return "ÿ";
			case 10011001:
				return "Ö";
			case 10011010:
				return "Ü";
			case 10011011:
				return "155";
			case 10011100:
				return "£";
			case 10011101:
				return "¥";
			case 10011110:
				return "158";
			case 10011111:
				return "ƒ";
			case 10100000:
				return "á";
			case 10100001:
				return "í";
			case 10100010:
				return "ó";
			case 10100011:
				return "ú";
			case 10100100:
				return "ñ";
			case 10100101:
				return "Ñ";
			case 10100110:
				return "166";
			case 10100111:
				return "˚";
			case 10101000:
				return "¿";
			case 10101001:
				return "169";
			case 10101010:
				return "¬";
			case 10101011:
				return "171";
			case 10101100:
				return "172";
			case 10101101:
				return "¡";
			case 10101110:
				return "«";
			case 10101111:
				return "»";
			case 10110000:
				return "176";
			case 10110001:
				return "177";
			case 10110010:
				return "178";
			case 10110011:
				return "179";
			case 10110100:
				return "180";
			case 10110101:
				return "181";
			case 10110110:
				return "182";
			case 10110111:
				return "183";
			case 10111000:
				return "184";
			case 10111001:
				return "185";
			case 10111010:
				return "186";
			case 10111011:
				return "187";
			case 10111100:
				return "188";
			case 10111101:
				return "189";
			case 10111110:
				return "190";
			case 10111111:
				return "191";
			case 11000000:
				return "192";
			case 11000001:
				return "193";
			case 11000010:
				return "194";
			case 11000011:
				return "195";
			case 11000100:
				return "196";
			case 11000101:
				return "197";
			case 11000110:
				return "198";
			case 11000111:
				return "199";
			case 11001000:
				return "200";
			case 11001001:
				return "201";
			case 11001010:
				return "202";
			case 11001011:
				return "203";
			case 11001100:
				return "204";
			case 11001101:
				return "205";
			case 11001110:
				return "206";
			case 11001111:
				return "207";
			case 11010001:
				return "208";
			case 11010000:
				return "209";
			case 11010010:
				return "210";
			case 11010011:
				return "211";
			case 11010100:
				return "212";
			case 11010101:
				return "213";
			case 11010110:
				return "214";
			case 11010111:
				return "215";
			case 11011000:
				return "216";
			case 11011001:
				return "217";
			case 11011010:
				return "218";
			case 11011011:
				return "219";
			case 11011100:
				return "220";
			case 11011101:
				return "221";
			case 11011110:
				return "222";
			case 11011111:
				return "223";
			case 11100000:
				return "ß";
			case 11100010:
				return "226";
			case 11100011:
				return "π";
			case 11100100:
				return "∑";
			case 11100101:
				return "229";
			case 11100110:
				return "µ";
			case 11100111:
				return "231";
			case 11101000:
				return "232";
			case 11101001:
				return "233";
			case 11101010:
				return "Ω";
			case 11101011:
				return "235";
			case 11101100:
				return "∞";
			case 11101101:
				return "237";
			case 11101110:
				return "238";
			case 11101111:
				return "239";
			case 11110000:
				return "240";
			case 11110001:
				return "±";
			case 11110010:
				return "≥";
			case 11110011:
				return "≤";
			case 11110100:
				return "244";
			case 11110101:
				return "245";
			case 11110110:
				return "÷";
			case 11110111:
				return "≈";
			case 11111000:
				return "˚";
			case 11111001:
				return "·˙";
			case 11111010:
				return "·";
			case 11111011:
				return "√";
			case 11111100:
				return "252";
			case 11111101:
				return "253";
			case 11111110:
				return "254";
			case 11111111:
				return "255";
			default:
				return "";
		}
	}
	
	void empty_binary(){
		binary[0] = '*';
		binary[1] = '*';
		binary[2] = '*';
		binary[3] = '*';
		binary[4] = '*';
		binary[5] = '*';
		binary[6] = '*';
		binary[7] = '*';
	}

}
