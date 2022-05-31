import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
function Square(props) {
  return (
    <button className="square"  onClick={props.onClick}>
      {props.value}
    </button>
  );
}


class Board extends React.Component {
  renderSquare(i) {
    return (
      <Square
        value={this.props.squares[i]}
        onClick={() => this.props.onClick(i)}
      />
    );
  }

  render() {
    return (
      <div>
        <div className="board-row">
          {this.renderSquare(0)}
          {this.renderSquare(1)}
          {this.renderSquare(2)}
          {this.renderSquare(3)}
          {this.renderSquare(4)}
          {this.renderSquare(5)}
          {this.renderSquare(6)}
          {this.renderSquare(7)}
          {this.renderSquare(8)}
        </div>
        <div className="board-row">
          {this.renderSquare(9)}
          {this.renderSquare(10)}
          {this.renderSquare(11)}
          {this.renderSquare(12)}
          {this.renderSquare(13)}
          {this.renderSquare(14)}
          {this.renderSquare(15)}
          {this.renderSquare(16)}
          {this.renderSquare(17)}
        </div>
        <div className="board-row">
          {this.renderSquare(18)}
          {this.renderSquare(19)}
          {this.renderSquare(20)}
          {this.renderSquare(21)}
          {this.renderSquare(22)}
          {this.renderSquare(23)}
          {this.renderSquare(24)}
          {this.renderSquare(25)}
          {this.renderSquare(26)}
        </div>
        <div className="board-row">
          {this.renderSquare(27)}
          {this.renderSquare(28)}
          {this.renderSquare(29)}
          {this.renderSquare(30)}
          {this.renderSquare(31)}
          {this.renderSquare(32)}
          {this.renderSquare(33)}
          {this.renderSquare(34)}
          {this.renderSquare(35)}
        </div>
        <div className="board-row">
          {this.renderSquare(36)}
          {this.renderSquare(37)}
          {this.renderSquare(38)}
          {this.renderSquare(39)}
          {this.renderSquare(40)}
          {this.renderSquare(41)}
          {this.renderSquare(42)}
          {this.renderSquare(43)}
          {this.renderSquare(44)}
        </div>
        <div className="board-row">
          {this.renderSquare(45)}
          {this.renderSquare(46)}
          {this.renderSquare(47)}
          {this.renderSquare(48)}
          {this.renderSquare(49)}
          {this.renderSquare(50)}
          {this.renderSquare(51)}
          {this.renderSquare(52)}
          {this.renderSquare(53)}
        </div>
        <div className="board-row">
          {this.renderSquare(54)}
          {this.renderSquare(55)}
          {this.renderSquare(56)}
          {this.renderSquare(57)}
          {this.renderSquare(58)}
          {this.renderSquare(59)}
          {this.renderSquare(60)}
          {this.renderSquare(61)}
          {this.renderSquare(62)}
        </div>
        <div className="board-row">
          {this.renderSquare(63)}
          {this.renderSquare(64)}
          {this.renderSquare(65)}
          {this.renderSquare(66)}
          {this.renderSquare(67)}
          {this.renderSquare(68)}
          {this.renderSquare(69)}
          {this.renderSquare(70)}
          {this.renderSquare(71)}
        </div>
        <div className="board-row">
          {this.renderSquare(72)}
          {this.renderSquare(73)}
          {this.renderSquare(74)}
          {this.renderSquare(75)}
          {this.renderSquare(76)}
          {this.renderSquare(77)}
          {this.renderSquare(78)}
          {this.renderSquare(79)}
          {this.renderSquare(80)}
        </div>
      </div>
    );
  }
}



class Game extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      history: [
        {
          squares: Array(81).fill(null)
        }
      ],
      stepNumber: 0,
      xIsNext: true,
      position: 0,
    };
  }


  onKeyPressed(event){
    const history = this.state.history.slice(0, this.state.stepNumber + 1);
    const current = history[history.length - 1];
    const squares = current.squares.slice();

    switch( event.keyCode ) {
        case 49:
          if(squares[this.state.position] === 1){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 1;
          break;
        case 50:
          if(squares[this.state.position] === 2){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 2;
          break;
        case 51:
          if(squares[this.state.position] === 3){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 3;
          break;
        case 52:
          if(squares[this.state.position] === 4){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 4;
          break;
        case 53:
          if(squares[this.state.position] === 5){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 5;
          break;
        case 54:
          if(squares[this.state.position] === 6){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 6;
          break;
        case 55:
          if(squares[this.state.position] === 7){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 7;
          break;
        case 56:
          if(squares[this.state.position] === 8){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 8;
          break;
        case 57:
          if(squares[this.state.position] === 9){
            squares[this.state.position] = null;
            break;
          }
          squares[this.state.position] = 9;
          break;
        case  8: case 46: case 48:
          squares[this.state.position] = null;
          break;
        default:
            break;

    }

    this.setState({
      history: history.concat([
        {
          squares:squares
        }
      ]),
      stepNumber:history.length
    });
  }

  componentDidMount() {
    document.addEventListener("keydown", this.onKeyPressed.bind(this));
    console.log("hello");
  }
  
  
  componentWillUnmount() {
    document.removeEventListener("keydown", this.onKeyPressed.bind(this));
}      


  handleClick(i) {
    this.setState({
      position: i
    });
  }
  

  render() {
    const history = this.state.history;
    const current = history[this.state.stepNumber];
    return (
      <div className="game">
        <div className="game-board">
          <Board
            
            onKeyDown={this.onKeyPressed} 
            onClick={i => this.handleClick(i)}
            tabIndex="0"
            squares={current.squares}
          />
        </div>
      </div>
    );
  }
}

// ========================================

const root = ReactDOM.createRoot(document.getElementById("root"));
root.render(<Game />);


